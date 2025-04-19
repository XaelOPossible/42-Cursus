#!/bin/bash

echo "🧹 Nettoyage des processus client/server minitalk..."

# Trouver tous les PID de ./server
SERVER_PIDS=$(ps aux | grep '[.]\/server' | awk '{print $2}')
CLIENT_PIDS=$(ps aux | grep '[.]\/client' | awk '{print $2}')

if [ -z "$SERVER_PIDS$CLIENT_PIDS" ]; then
    echo "✅ Aucun processus ./client ou ./server à tuer."
    exit 0
fi

# Tuer les processus ./server
for pid in $SERVER_PIDS; do
    echo "❌ kill -9 serveur PID: $pid"
    kill -9 "$pid"
done

# Tuer les processus ./client
for pid in $CLIENT_PIDS; do
    echo "❌ kill -9 client PID: $pid"
    kill -9 "$pid"
done

echo "✅ Tous les processus ./client et ./server ont été stoppés."
