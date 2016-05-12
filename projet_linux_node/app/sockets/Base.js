var io; 

var IO = {
    set: function (IO) { // Cette fonction sera appelé dans le fichier app.js et valorisera la variable io
        io = IO;
        var $this = this; // On enregistre le contexte actuel dans une variable

        
    },
    get: function () {
        return io;
    },
    connection: function (callback) {
        io.on('connection', function (s) {
            // On envoie le nombre de personnes actuellement sur le socket à tout le monde (sauf la personne qui vient de se connecter)
            s.broadcast.emit('Data', io.sockets.sockets.length);

            callback(s);
        });
    },
   };

module.exports = IO;