let IdSeleccionado = 0;

const txtTitulo = document.getElementById('txtTitulo');
const lstTransaccion = document.getElementById('lstTransaccion');
const txtDescripcion = document.getElementById('txtDescripcion');
const numPrecio = document.getElementById('numPrecio');
const numPuertas = document.getElementById('numPuertas');
const numKMs = document.getElementById('numKMs');
const numPotencia = document.getElementById('numPotencia');

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
        fila1.setAttribute('data-puertas', element.puertas);
        fila1.setAttribute('data-kilometraje', element.kilometraje);
        fila1.setAttribute('data-potencia', element.potencia);

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
    return tabla;
};

function agregarManejadorTr(tr){
    if(tr){
        tr.addEventListener('click', function(e){
            IdSeleccionado = tr.dataset.id; //Muestra id de ese tr
            txtTitulo.value=tr.dataset.titulo;
            lstTransaccion.value = tr.dataset.transaccion;
            txtDescripcion.value = tr.dataset.descripcion;
            numPrecio.value = tr.dataset.precio;
            numPuertas.value = tr.dataset.puertas;
            numKMs.value = tr.dataset.kilometraje;
            numPotencia.value = tr.dataset.potencia;            
        });
    }
}

export function obtenerIdSeleccionado(){
    return IdSeleccionado;
}