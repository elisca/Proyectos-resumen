export class Anuncio{
    constructor(id, titulo, transaccion="Venta",descripcion, precio){
        this.Id = id;
        this.Titulo = titulo;
        this.Transaccion = transaccion;
        this.Descripcion = descripcion;
        this.Precio = precio;
    }

    set Id(id){
        if(id>=0){
            this.id = id;
        }
        else{
            console.error("Id no válido.");
            this.id=-1;
        }
    }

    set Titulo(titulo){
        this.titulo = titulo;
    }

    set Transaccion(transaccion){
        if(transaccion=="Venta" || transaccion=="Alquiler" || transaccion=="Permuta"){
            this.transaccion = transaccion;
        }
        else{
            console.error("Transacción no válida.");
            this.transaccion="<error>";
        }
    }

    set Descripcion(descripcion){
        this.descripcion = descripcion;
    }

    set Precio(precio){
        if(precio>=0){
            this.precio = precio;
        }
        else{
            console.error("Precio no válido.");
            this.precio=-1;
        }
    }

    get Id(){
        return this.id;
    }

    get Titulo(){
        return this.titulo;
    }

    get Transaccion(){
        return this.transaccion;
    }

    get Descripcion(){
        return this.descripcion;
    }

    get Precio(){
        return this.precio;
    }
}

export default class Anuncio_Auto extends Anuncio{
    constructor(id, titulo, transaccion="Venta",descripcion, precio, puertas, kilometraje, potencia){
        super(id, titulo, transaccion, descripcion, precio);
        this.Puertas = puertas;
        this.Kilometraje = kilometraje;
        this.Potencia = potencia;
    }

    set Puertas(value){
        if(value>=0){
            this.puertas = value;
        }
        else{
            console.error("Cantidad de puertas no válida.");
            this.puertas=-1;
        }
    }

    set Kilometraje(value){
        if(value>=0){
            this.kilometraje = value;
        }
        else{
            console.error("Kilometraje no válido.");
            this.kilometraje=-1;
        }
    }

    set Potencia(value){
        if(value>=0){
            this.potencia = value;
        }
        else{
            console.error("Potencia no válida.");
            this.potencia=-1;
        }
    }

    get Puertas(){
        return this.puertas;
    }

    get Kilometraje(){
        return this.kilometraje;
    }

    get Potencia(){
        return this.potencia;
    }
}