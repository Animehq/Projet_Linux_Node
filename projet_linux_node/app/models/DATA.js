var mongoose = require('mongoose'), // Nous appelons le module mongoose
    Schema = mongoose.Schema; // Nous créons un schéma mongoose

var schema = new Schema({
    id : {type: String, required: true},
    CPU : {type: String, required: true},
    RAM active : {type: String, required: true},
    RAM utilisée : {type: String, required: true},
    Debit montant : {type: String, required: true},
    Debit descendant : {type: String, required: true}
    
});

exports.model = mongoose.model('Data', schema, 'Datas');
