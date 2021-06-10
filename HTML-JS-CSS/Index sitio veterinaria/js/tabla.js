/*INSERTAR TABLA*/
/*
const cuerpo = document.getElementById('cuerpoHTML');
cuerpo.appendChild(crearTabla(listaPersonas));
*/

//Crea una tabla con los datos de la lista

let IdSeleccionado = 0;

const txtTitulo = document.getElementById('txtTitulo');
const txtDescripcion = document.getElementById('txtDescripcion');
const rdoPerro = document.getElementById('rdoPerro');
const rdoGato = document.getElementById('rdoGato');
const txtPrecio = document.getElementById('txtPrecio');
const txtRaza = document.getElementById('txtRaza');
const datNacimiento = document.getElementById('datNacimiento');
const sVacunacion = document.getElementById('sVacunacion');

export function crearTabla(lista){
    //Cantidad de columnas de la tabla a crear
    const CANT_COLUMNAS = Object.keys(lista[0]).length;

    //Creacion de elementos de la tabla
    const tabla = document.createElement('table');
    const encabezado = document.createElement('thead');
    const fila0 = document.createElement('tr');

    const cuerpoTabla = document.createElement('tbody');

    //Crea dinamicamente los encabezados en base a claves del primer elemento
    Object.keys(lista[0]).forEach(element => {
        const celdaEncabezado = document.createElement('th');
        celdaEncabezado.setAttribute('class', 'tablaEncabezado');
        celdaEncabezado.appendChild(document.createTextNode(element));
        encabezado.appendChild(celdaEncabezado);
    });

    //Datos de encabezado
    //Ensamblado de nodos de la tabla
    tabla.appendChild(encabezado);
    tabla.appendChild(cuerpoTabla);

    //Datos de cuerpo
    lista.forEach(element => {
        //Creacion de fila y celdas para ese elemento
        const fila1 = document.createElement('tr');

        fila1.setAttribute('data-id', element.id);
        fila1.setAttribute('data-titulo', element.titulo);
        fila1.setAttribute('data-transaccion', element.transaccion);
        fila1.setAttribute('data-descripcion', element.descripcion);
        fila1.setAttribute('data-precio', element.precio);
        fila1.setAttribute('data-animal', element.animal);
        fila1.setAttribute('data-raza', element.raza);
        fila1.setAttribute('data-fecha', element.fechaNacimiento);
        fila1.setAttribute('data-vacunacion', element.vacunacion);

        agregarManejadorTr(fila1);

        Object.keys(element).forEach(clave =>{
            const celdaCuerpo0 = document.createElement('td');
            celdaCuerpo0.appendChild(document.createTextNode(element[clave]));
            celdaCuerpo0.setAttribute('style', 'background-color: yellowgreen; padding: 5px;');
            fila1.appendChild(celdaCuerpo0);
        });
        
        //Adjunta la fila completa al cuerpo de la tabla
        cuerpoTabla.appendChild(fila1);
    });

    //Pie de tabla
    /*
    const pieTabla = document.createElement('tfoot');
    const fila2 = document.createElement('tr');
    const celdaPieTabla = document.createElement('td');

    celdaPieTabla.appendChild(document.createTextNode("Pie de tabla")); //Texto del pie
    
    pieTabla.appendChild(fila2);
    fila2.appendChild(celdaPieTabla);
    celdaPieTabla.setAttribute('colspan', CANT_COLUMNAS); //Combina celdas
    celdaPieTabla.setAttribute('align', 'center'); //Centra el contenido

    tabla.appendChild(pieTabla);
    */

    return tabla;
};

function agregarManejadorTr(tr){
    if(tr){
        tr.addEventListener('click', function(e){
            IdSeleccionado = tr.dataset.id; //Muestra id de ese tr
            txtTitulo.value = tr.dataset.titulo;
            txtDescripcion.value = tr.dataset.descripcion;
            
            if(tr.dataset.animal=='perro'){
                rdoPerro.checked = true;
                rdoGato.checked = false;
            }

            if(tr.dataset.animal=='gato'){
                rdoPerro.checked = false;
                rdoGato.checked = true;
            }

            txtPrecio.value = tr.dataset.precio;
            txtRaza.value = tr.dataset.raza;
            datNacimiento.value = tr.dataset.fecha;
            sVacunacion.value = tr.dataset.vacunacion;
        });
    }
}

export function obtenerIdSeleccionado(){
    return IdSeleccionado;
}