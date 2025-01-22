/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axemicha <axemicha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:37:02 by axemicha          #+#    #+#             */
/*   Updated: 2025/01/17 06:28:30 by axemicha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// Fonction pour dessiner l'arrière-plan
void render_background(t_data *data)
{
    int i;
    int y;

    if (!data || !data->map) // Vérification que data et map sont valides
        return;

    y = 0;
    while (data->map[y] != NULL) // Boucle sur les lignes
    {
        i = 0;
        while (data->map[y][i] != '\0') // Boucle sur les colonnes
        {
            // Vérification des images avant de les utiliser
            if (data->map[y][i] == data->content.wall && data->img.img_wall)
                print_img(data, data->img.img_wall, i, y);
            else if (data->map[y][i] == data->content.space && data->img.img_floor)
                print_img(data, data->img.img_floor, i, y);
            i++;
        }
        y++;
    }
}

// Fonction pour dessiner les autres éléments
void render_other(t_data *data)
{
    int i;
    int y;

    if (!data || !data->map) // Vérification que data et map sont valides
        return;

    y = 0;
    while (data->map[y] != NULL) // Boucle sur les lignes
    {
        i = 0;
        while (data->map[y][i] != '\0') // Boucle sur les colonnes
        {
            // Vérification des images avant de les utiliser
            if (data->map[y][i] == data->content.collect && data->img.img_collect)
                print_img(data, data->img.img_collect, i, y);
            if (data->map[y][i] == data->content.player && data->img.img_player)
            {
                data->pos.x = i * data->img.width; // Mise à jour de la position
                data->pos.y = y * data->img.height;
                print_img(data, data->img.img_player, i, y);
            }
            if (data->map[y][i] == data->content.exit && data->img.img_exit)
                print_img(data, data->img.img_exit, i, y);
            i++;
        }
        y++;
    }
}

// Fonction principale de rendu
int render(t_data *data)
{
    if (!data || !data->mlx_ptr || !data->mlx_win) // Vérification des pointeurs critiques
        return (0);

    render_background(data); // Rendu de l'arrière-plan
    render_other(data);      // Rendu des autres éléments
    return (0);
}

// Fonction pour initialiser la boucle principale
void core_render(t_data *data)
{
    if (!data || !data->mlx_ptr) // Vérification que data et mlx_ptr sont valides
    {
        ft_printf("Erreur : données non initialisées\n");
        return;
    }

    data->mlx_win = mlx_new_window(data->mlx_ptr,
            (data->width * data->img.width), (data->height * data->img.height),
            "So_long");
    if (data->mlx_win == NULL) // Vérification que la fenêtre a bien été créée
    {
        free(data->mlx_ptr);
        ft_printf("Erreur : fenêtre non créée\n");
        return;
    }

    // Hook pour les événements et la boucle principale
    mlx_loop_hook(data->mlx_ptr, &render, data);
    mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
    mlx_hook(data->mlx_win, 17, 0, &end, data);

    ft_printf("Début de la boucle principale\n");
    mlx_loop(data->mlx_ptr); // Boucle principale
    ft_printf("Fin de la boucle principale\n");

    end(data); // Libération des ressources après la boucle
}

// Fonction pour afficher une image
void print_img(t_data *data, void *img, int x, int y)
{
    if (!data || !data->mlx_ptr || !data->mlx_win || !img) // Vérification des arguments
        return;

    // Placement de l'image sur la fenêtre
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
        data->img.width * x, data->img.height * y);
}
