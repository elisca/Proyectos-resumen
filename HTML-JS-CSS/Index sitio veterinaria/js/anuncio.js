export class Anuncio{
    constructor(id, titulo, transaccion="venta",descripcion, precio){
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
        }
    }

    set Titulo(titulo){
        this.titulo = titulo;
    }

    set Transaccion(transaccion){
        this.transaccion = "venta";
    }

    set Descripcion(descripcion){
        this.descripcion = descripcion;
    }

    set Precio(precio){
        if(precio>=0){
            this.precio = precio;
        }
    }

    get Id(){
        return this.id;
    }

    get Titulo(){
        return this.titulo;
    }

    get Descripcion(){
        return this.descripcion;
    }

    get Precio(){
        return this.precio;
    }
}

export default class Anuncio_Mascota extends Anuncio{
    constructor(id, titulo, transaccion="venta",descripcion, precio, animal, raza, fechaNacimiento, vacunacion){
        super(id, titulo, transaccion, descripcion, precio);
        this.Animal = animal;
        this.Raza = raza;
        this.FechaNacimiento = fechaNacimiento;
        this.Vacunacion = vacunacion;
    }

    set Animal(animal){
        let auxAnimal = animal.toLowerCase();

        if(auxAnimal=='perro' || auxAnimal=='gato'){
            this.animal = auxAnimal;
        }
    }

    set Raza(raza){
        this.raza = raza;
    }

    set FechaNacimiento(fechaNac){
        this.fechaNacimiento = fechaNac;
    }

    set Vacunacion(vacunacion){
        let auxVacunacion =  vacunacion.toLowerCase();

        if(auxVacunacion=='si' || auxVacunacion=='no'){
            this.vacunacion=auxVacunacion;
        }
        else{
            console.error("Valor de vacunacion incorrecto.");
        }
    }

    get Animal(){
        return this.animal;
    }

    get Raza(){
        return this.raza;
    }

    get FechaNacimiento(){
        return this.fechaNacimiento;
    }

    get Vacunacion(){
        return this.vacunacion;
    }

    MostrarDatosAnuncio(){
        return `Id: ${this.Id} Titulo: ${this.Titulo} Descripcion: ${this.Descripcion} Animal: ${this.Animal} Precio: $${this.Precio} Raza: ${this.Raza} Fecha de nacimiento: ${this.FechaNacimiento} Vacunación: ${this.Vacunacion}`;
    }
}