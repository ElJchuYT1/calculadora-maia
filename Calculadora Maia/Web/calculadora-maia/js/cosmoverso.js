/* ==========================================================================
   BASE DE DATOS: 20 SELLOS / NAHUALES
   ========================================================================== */
const SELLOS_DB = [
  {
    id: 0, nombre: "Imix'", nahual: "Dragón / Cocodrilo",
    naturaleza: "Favorable / Inicio / Nutrición",
    accion: "Ideal para iniciar proyectos, sembrar ideas y emprender negocios.",
    evitar: "No dejes proyectos a medias ni descuides tus emociones básicas.",
    talentos: "Gran fuerza creadora, instintivo y protector. Desafío: Manejar la impulsividad y el caos inicial.",
    ceremonial: null
  },
  {
    id: 1, nombre: "Ik'", nahual: "Viento",
    naturaleza: "Comunicación / Espíritu / Agilidad",
    accion: "Propicio para dialogar, enseñar, difundir mensajes y aclarar malos entendidos.",
    evitar: "Evita la dispersión mental o decir palabras hirientes.",
    talentos: "Gran comunicador, orador e inspirador. Desafío: Vencer la inconstancia y la volatilidad.",
    ceremonial: null
  },
  {
    id: 2, nombre: "Ak'b'al", nahual: "Noche / Akabal",
    naturaleza: "Introspección / Misterio / Planificación",
    accion: "Propicio para meditar, analizar riesgos y trabajar en secreto.",
    evitar: "Evita el aislamiento excesivo o postergar decisiones por miedo.",
    talentos: "Profunda intuición, mente analítica y guardián de secretos. Desafío: Superar las dudas internas.",
    ceremonial: null
  },
  {
    id: 3, nombre: "K'an", nahual: "Semilla / Red",
    naturaleza: "Germinación / Abundancia / Potencial",
    accion: "Día para almacenar recursos, planificar cosechas y cultivar sabiduría.",
    evitar: "No impongas rigidez ni tengas impaciencia con los procesos.",
    talentos: "Capacidad de florecer en cualquier entorno y paciencia. Desafío: No estancarse en la zona de confort.",
    ceremonial: null
  },
  {
    id: 4, nombre: "Chikchan", nahual: "Serpiente",
    naturaleza: "Vitalidad / Pasión / Fuerza Vital",
    accion: "Excelente para actividades físicas, sanación corporal y despertar instintivo.",
    evitar: "Evita arranques de ira o comportamientos posesivos.",
    talentos: "Energía física desbordante y magnetismo personal. Desafío: Canalizar la fuerza sin destruir.",
    ceremonial: null
  },
  {
    id: 5, nombre: "Kimi", nahual: "Muerte / Enlazador de Mundos",
    naturaleza: "Transmutación / Cierre / Renacimiento",
    accion: "Día para soltar el pasado, perdonar y cerrar ciclos inconclusos.",
    evitar: "No te aferres a lo que ya no funciona por miedo al cambio.",
    talentos: "Facilidad para adaptarse, serenidad y habilidad negociadora. Desafío: Soltar el control.",
    ceremonial: null
  },
  {
    id: 6, nombre: "Manik'", nahual: "Mano / Venado",
    naturaleza: "Sanación / Herramienta / Realización",
    accion: "Propicio para trabajar con las manos, curar y concluir tareas pendientes.",
    evitar: "Evita sobrecargarte de responsabilidades ajenas.",
    talentos: "Vocación de servicio, habilidad artesanal y curativa. Desafío: Aprender a recibir ayuda.",
    ceremonial: null
  },
  {
    id: 7, nombre: "Lamat", nahual: "Estrella / Conejo",
    naturaleza: "Armonía / Belleza / Arte",
    accion: "Ideal para crear arte, embellecer espacios y buscar acuerdos pacíficos.",
    evitar: "Evita las discusiones estériles o la vanidad excesiva.",
    talentos: "Sentido estético elevado, diplomacia y brillo social. Desafío: Superar el perfeccionismo.",
    ceremonial: null
  },
  {
    id: 8, nombre: "Muluk", nahual: "Ofrenda / Agua / Toj",
    naturaleza: "Purificación / Emoción / Nivelación",
    accion: "Excelente para rituales de agradecimiento, purificación con agua y pago de deudas.",
    evitar: "Evita reprimir sentimientos o victimizarte.",
    talentos: "Sensibilidad espiritual e intuición fluida. Desafío: No dejarse arrastrar por tormentas emocionales.",
    ceremonial: "Tu Kin está vinculado a la Ofrenda (Toj). Tradicionalmente es el día para pedir perdón, pagar deudas espirituales y prender el fuego sagrado."
  },
  {
    id: 9, nombre: "Ok", nahual: "Perro / Lealtad",
    naturaleza: "Fidelidad / Trabajo en Equipo / Guía",
    accion: "Día para fortalecer lazos afectivos, colaborar en grupo y proteger a la familia.",
    evitar: "Evita la desconfianza infundada o los celos.",
    talentos: "Lealtad inquebrantable, gran sentido de protección y guía emocional. Desafío: Superar el apego excesivo.",
    ceremonial: null
  },
  {
    id: 10, nombre: "Chuwen", nahual: "Mono / Artesano / B'atz'",
    naturaleza: "Creatividad / Juego / Hilo del Tiempo",
    accion: "Propicio para inventar, reír, practicar artes y tejer nuevas metas.",
    evitar: "Evita tomarte las cosas demasiado en broma o actuar con irresponsabilidad.",
    talentos: "Ingenio ilimitado, destreza y sentido del humor. Desafío: Mantener la seriedad cuando se requiere.",
    ceremonial: "Naciste bajo el Sello de los tejedores del tiempo. El día 8 B'atz' (u 8 Chuen) se celebra el inicio del año nuevo del conteo sagrado."
  },
  {
    id: 11, nombre: "Eb'", nahual: "Humano / Camino",
    naturaleza: "Sabiduría / Libre Albedrío / Ascenso",
    accion: "Ideal para emprender viajes, tomar decisiones autónomas y cultivar la mente.",
    evitar: "Evita la indecisión o actuar bajo presión social.",
    talentos: "Receptividad, capacidad de aprendizaje y libertad de criterio. Desafío: Asumir la responsabilidad de tus elecciones.",
    ceremonial: null
  },
  {
    id: 12, nombre: "B'en", nahual: "Caña / Caminante del Cielo",
    naturaleza: "Fuerza Pilar / Liderazgo / Exploración",
    accion: "Día para defender principios, explorar nuevos horizontes y guiar a otros.",
    evitar: "Evita la inflexibilidad o el autoritarismo.",
    talentos: "Liderazgo natural, coraje y principios sólidos. Desafío: Flexibilizar tus posturas ante los demás.",
    ceremonial: null
  },
  {
    id: 13, nombre: "IX", nahual: "Jaguar / Magia",
    naturaleza: "Astucia / Misticismo / Conexión Terrestre",
    accion: "Propicio para conectar con la naturaleza, agudizar la percepción y meditar en la noche.",
    evitar: "Evita la manipulación o actuar a espaldas de los demás.",
    talentos: "Percepción psíquica, elegancia y fuerza misteriosa. Desafío: Usar tu poder con transparencia.",
    ceremonial: null
  },
  {
    id: 14, nombre: "Men", nahual: "Águila",
    naturaleza: "Visión Panorámica / Mente Superior / Esperanza",
    accion: "Excelente para planificar a largo plazo, diseñar estrategias y ver el panorama completo.",
    evitar: "Evita perderte en los detalles minuciosos o volverte hipercrítico.",
    talentos: "Claridad mental, ambición noble y perspectiva amplia. Desafío: No desconectarse de la realidad cotidiana.",
    ceremonial: null
  },
  {
    id: 15, nombre: "K'ib'", nahual: "Búho / Guerrero / Cera",
    naturaleza: "Cuestionamiento / Perdón / Luz en la Oscuridad",
    accion: "Día para auto-evaluarse, pedir consejo a ancianos y limpiar cargas kármicas.",
    evitar: "Evita el auto-juicio despiadado o el resentimiento.",
    talentos: "Valentía intelectual, capacidad de reconciliación y rigor ético. Desafío: Aprender a perdonarse a uno mismo.",
    ceremonial: null
  },
  {
    id: 16, nombre: "Kab'an", nahual: "Tierra / Movimiento",
    naturaleza: "Sincronía / Evolución / Ritmo Terrestre",
    accion: "Propicio para sincronizar planes, cuidar el medio ambiente y fluir con el cambio.",
    evitar: "Evita la terquedad o resistirte a las transformaciones inevitables.",
    talentos: "Fuerza realizadora, sentido de sincronía y practicidad. Desafío: Adaptarse al caos sin perder la calma.",
    ceremonial: null
  },
  {
    id: 17, nombre: "Etz'nab'", nahual: "Espejo / Cuchillo",
    naturaleza: "Verdad / Claridad / Discernimiento",
    accion: "Ideal para cortar ilusiones, decir la verdad y analizar situaciones objetivamente.",
    evitar: "Evita los juicios hirientes o proyectar tus sombras en los demás.",
    talentos: "Discernimiento filoso, honestidad y búsqueda de la verdad pura. Desafío: Cultivar la compasión al decir la verdad.",
    ceremonial: null
  },
  {
    id: 18, nombre: "Kawak", nahual: "Tormenta / Catalizador",
    naturaleza: "Renovación / Energía / Aceleración",
    accion: "Propicio para romper estructuras obsoletas, renovar la casa y liberar tensiones.",
    evitar: "Evita dramatizar los desacuerdos o generar conflictos innecesarios.",
    talentos: "Poder transformador, dinamismo y entusiasmo contagioso. Desafío: Mantener el centro en medio de la tempestad.",
    ceremonial: null
  },
  {
    id: 19, nombre: "Ajaw", nahual: "Sol / Señor",
    naturaleza: "Iluminación / Maestría / Unificación",
    accion: "Día de la luz, el agradecimiento a los ancestros y la culminación de metas.",
    evitar: "Evita la soberbia o creerse superior a los demás.",
    talentos: "Claridad espiritual, maestría de vida y luz interior. Desafío: Mantener la humildad del verdadero líder.",
    ceremonial: "Tu Kin pertenece a un día ceremonial sagrado (Ajaw). Es una fecha ideal para dar gracias a los ancestros y pedir claridad espiritual."
  }
];

/* ==========================================================================
   BASE DE DATOS: 13 TONOS NUMERALES
   ========================================================================== */
const TONOS_DB = [
  { numero: 1, nombre: "Magnético", ejecucion: "Atrae las cosas por sí mismo, decide metas e inicia propósitos con fuerza unilateral." },
  { numero: 2, nombre: "Lunar", ejecucion: "Identifica los obstáculos, equilibra polaridades y aprende a través del contraste." },
  { numero: 3, nombre: "Eléctrico", ejecucion: "Activa la energía, comunica eficazmente y sirve de vínculo de unión entre personas." },
  { numero: 4, nombre: "Auto-existente", ejecucion: "Mide, estructura y da forma práctica a las ideas para convertirlas en realidades." },
  { numero: 5, nombre: "Entonado", ejecucion: "Reúne recursos, asume el mando y otorga poder de decisión e independencia." },
  { numero: 6, nombre: "Rítmico", ejecucion: "Organiza la eficiencia, gestiona la igualdad y mantiene el equilibrio en el movimiento." },
  { numero: 7, nombre: "Resonante", ejecucion: "Canaliza información elevada, inspira misticismo y se alinea con la sintonía adecuada." },
  { numero: 8, nombre: "Galáctico", ejecucion: "Modela la integridad, armoniza sus creencias con sus actos y vive con ética." },
  { numero: 9, nombre: "Solar", ejecucion: "Acelera la acción, moviliza proyectos y concreta intenciones con entusiasmo." },
  { numero: 10, nombre: "Planetario", ejecucion: "Perfecciona el trabajo, manifiesta resultados tangibles y alcanza la excelencia." },
  { numero: 11, nombre: "Espectral", ejecucion: "Disuelve lo que ya no sirve, libera tensiones y simplifica las estructuras." },
  { numero: 12, nombre: "Cristal", ejecucion: "Coopera con la comunidad, comparte conocimientos y promueve soluciones conjuntas." },
  { numero: 13, nombre: "Cósmico", ejecucion: "Trascendencia pura, culmina grandes ciclos con éxito y se prepara para el siguiente nivel." }
];

const HAAB_MONTHS = ["Pop", "Wo'", "Sip", "Sotz'", "Sek", "Xul", "Yaxk'in'", "Mol", "Ch'en", "Yax", "Sak'", "Keh", "Mak", "K'ank'in", "Muwan", "Pax", "K'ayab'", "Kumk'u", "Wayeb'"];

/* ==========================================================================
   FUNCIONES MATEMÁTICAS Y ALGORITMOS
   ========================================================================== */

function getJulianDayNumber(year, month, day) {
  let a = Math.floor((14 - month) / 12);
  let y = year + 4800 - a;
  let m = month + 12 * a - 3;
  return day + Math.floor((153 * m + 2) / 5) + 365 * y + Math.floor(y / 4) - Math.floor(y / 100) + Math.floor(y / 400) - 32045;
}

// Convertir fecha gregoriana a Kin, Tono, Sello y Haab
function calculateMayaDataFromDate(dateString) {
  const parts = dateString.split('-');
  const year = parseInt(parts[0], 10);
  const month = parseInt(parts[1], 10);
  const day = parseInt(parts[2], 10);

  const jdn = getJulianDayNumber(year, month, day);
  const daysElapsed = jdn - 584283; // Correlación GMT

  // Kin (1 - 260)
  let kin = ((daysElapsed + 159) % 260) + 1;
  if (kin <= 0) kin += 260;

  // Tono (1 - 13)
  const tonoNum = ((daysElapsed + 3) % 13) + 1;

  // Sello (0 - 19)
  let selloIndex = (daysElapsed + 19) % 20;
  if (selloIndex < 0) selloIndex += 20;

  // Haab
  let haabDayInYear = (daysElapsed + 348) % 365;
  if (haabDayInYear < 0) haabDayInYear += 365;

  let monthIndex = Math.floor(haabDayInYear / 20);
  let dayInMonth = haabDayInYear % 20;
  let haabString = (monthIndex === 18) ? `${dayInMonth} Wayeb'` : `${dayInMonth} ${HAAB_MONTHS[monthIndex]}`;

  return { kin, tonoNum, selloIndex, haabString, birthDate: new Date(year, month - 1, day) };
}

// Hallar el Kin (1-260) dado el Tono (1-13) y el Sello (0-19)
function calculateKinFromTonoSello(tonoNum, selloIndex) {
  for (let k = 1; k <= 260; k++) {
    let t = ((k - 1) % 13) + 1;
    let s = (k - 1) % 20;
    if (t === tonoNum && s === selloIndex) {
      return k;
    }
  }
  return 1;
}

// Evaluar la Metáfora del Maíz (4 cuadrantes de 65 kines)
function getCornStage(kin) {
  if (kin >= 1 && kin <= 65) {
    return {
      nombre: "Siembra (Estación Roja - Iniciación)",
      desc: "Tu energía pertenece al primer cuadrante del Tzolk'in (Kines 1-65). Eres un sembrador de intenciones, tu impulso natural es iniciar proyectos y plantar semillas conceptuales."
    };
  } else if (kin >= 66 && kin <= 130) {
    return {
      nombre: "Germinación (Estación Blanca - Purificación)",
      desc: "Tu energía está en el segundo cuadrante (Kines 66-130). Tu misión involucra nutrir las ideas en la oscuridad del suelo, purificar procesos y hacer crecer raíces fuertes."
    };
  } else if (kin >= 131 && kin <= 195) {
    return {
      nombre: "Florecimiento (Estación Azul - Transformación)",
      desc: "Tu energía reside en el tercer cuadrante (Kines 131-195). Representas la transformación del brote que sale a la luz, aportando creatividad, color y diversificación."
    };
  } else {
    return {
      nombre: "Cosecha (Estación Amarilla - Maduración)",
      desc: "Tu energía pertenece al último cuadrante (Kines 196-260). Tu propósito es madurar los frutos, cosechar los resultados del esfuerzo colectivo y almacenar la sabiduría."
    };
  }
}

/* ==========================================================================
   INICIALIZACIÓN E INTERFAZ DE USUARIO
   ========================================================================== */

document.addEventListener('DOMContentLoaded', () => {
  const selectTono = document.getElementById('select-tono');
  const selectSello = document.getElementById('select-sello');
  const modeDate = document.getElementById('mode-date');
  const modeDirect = document.getElementById('mode-direct');
  const blockDate = document.getElementById('block-date');
  const blockDirect = document.getElementById('block-direct');
  const birthInput = document.getElementById('birth-date');
  const form = document.getElementById('cosmo-form');

  // Rellenar selectores
  TONOS_DB.forEach(t => {
    const opt = document.createElement('option');
    opt.value = t.numero;
    opt.textContent = `Tono ${t.numero} - ${t.nombre}`;
    selectTono.appendChild(opt);
  });

  SELLOS_DB.forEach(s => {
    const opt = document.createElement('option');
    opt.value = s.id;
    opt.textContent = `${s.id + 1}. ${s.nombre} (${s.nahual})`;
    selectSello.appendChild(opt);
  });

  // Alternar modos de entrada
  modeDate.addEventListener('change', () => {
    blockDate.classList.remove('hidden');
    blockDirect.classList.add('hidden');
  });

  modeDirect.addEventListener('change', () => {
    blockDirect.classList.remove('hidden');
    blockDate.classList.add('hidden');
  });

  // Fecha predeterminada
  birthInput.value = new Date().toISOString().split('T')[0];

  // Enviar formulario
  form.addEventListener('submit', (e) => {
    e.preventDefault();

    let kin, tonoNum, selloIndex, haabStr = "No disponible en modo directo", birthDateObj = null;

    if (modeDate.checked) {
      if (!birthInput.value) return;
      const data = calculateMayaDataFromDate(birthInput.value);
      kin = data.kin;
      tonoNum = data.tonoNum;
      selloIndex = data.selloIndex;
      haabStr = data.haabString;
      birthDateObj = data.birthDate;
    } else {
      tonoNum = parseInt(selectTono.value, 10);
      selloIndex = parseInt(selectSello.value, 10);
      kin = calculateKinFromTonoSello(tonoNum, selloIndex);
    }

    renderCosmoverso(kin, tonoNum, selloIndex, haabStr, birthDateObj);
  });
});

/* Renderizar todas las secciones */
function renderCosmoverso(kin, tonoNum, selloIndex, haabStr, birthDateObj) {
  const sello = SELLOS_DB[selloIndex];
  const tono = TONOS_DB.find(t => t.numero === tonoNum);
  const cornStage = getCornStage(kin);

  // 1. Alerta Ceremonial (Función 3)
  const alertContainer = document.getElementById('ceremonial-alert');
  if (sello.ceremonial) {
    alertContainer.innerHTML = `<strong>🔥 Aviso de Fecha Sagrada:</strong> ${sello.ceremonial}`;
    alertContainer.classList.remove('hidden');
  } else {
    alertContainer.classList.add('hidden');
  }

  // 2. Encabezado de Coordenada
  document.getElementById('res-kin-title').textContent = `Kin ${kin}: ${tono.nombre} ${sello.nombre}`;
  document.getElementById('res-wheel-coord').textContent = `${tonoNum} ${sello.nombre} | Nahual: ${sello.nahual}`;

  // 3. Función 1: Adivinación y Augurios
  document.getElementById('f1-naturaleza').textContent = sello.naturaleza;
  document.getElementById('f1-accion').textContent = sello.accion;
  document.getElementById('f1-evitar').textContent = sello.evitar;

  // 4. Función 2: Perfil de Personalidad
  document.getElementById('f2-sello-nombre').textContent = `${sello.nombre} (${sello.nahual})`;
  document.getElementById('f2-sello-desc').textContent = sello.talentos;
  document.getElementById('f2-tono-num').textContent = tono.numero;
  document.getElementById('f2-tono-nombre').textContent = tono.nombre;
  document.getElementById('f2-tono-desc').textContent = tono.ejecucion;

  // 5. Función 4: Ciclo Agrícola
  const concepcionEl = document.getElementById('f4-concepcion');
  if (birthDateObj) {
    const concepcionDate = new Date(birthDateObj.getTime() - (260 * 24 * 60 * 60 * 1000));
    const options = { year: 'numeric', month: 'long', day: 'numeric' };
    concepcionEl.textContent = concepcionDate.toLocaleDateString('es-ES', options);
  } else {
    concepcionEl.textContent = "Ingresa tu fecha de nacimiento exacta para calcular la fecha de concepción.";
  }
  document.getElementById('f4-etapa-nombre').textContent = cornStage.nombre;
  document.getElementById('f4-etapa-desc').textContent = cornStage.desc;

  // 6. Función 5: Rueda Calendárica
  document.getElementById('f5-coordenada').textContent = `${tonoNum} ${sello.nombre} ${haabStr}`;
  
  const retornoFechaEl = document.getElementById('f5-retorno-fecha');
  const retornoStatusEl = document.getElementById('f5-retorno-status');

  if (birthDateObj) {
    const retornoDate = new Date(birthDateObj);
    retornoDate.setFullYear(retornoDate.getFullYear() + 52);
    const options = { year: 'numeric', month: 'long', day: 'numeric' };
    retornoFechaEl.textContent = `Fecha exacta: ${retornoDate.toLocaleDateString('es-ES', options)}`;

    const today = new Date();
    if (today < retornoDate) {
      const diffYears = ((retornoDate - today) / (1000 * 60 * 60 * 24 * 365.25)).toFixed(1);
      retornoStatusEl.textContent = `A los 52 años de edad experimentarás tu segundo nacimiento maya, donde la Rueda Calendárica volverá exactamente a la misma posición del día en que naciste. Faltan aproximadamente ${diffYears} años.`;
    } else {
      retornoStatusEl.textContent = "¡Ya has alcanzado tu segundo nacimiento maya! Te encuentras viviendo en tu segundo gran ciclo de la Rueda Calendárica.";
    }
  } else {
    retornoFechaEl.textContent = "Requiere fecha de nacimiento.";
    retornoStatusEl.textContent = "Selecciona el modo por fecha de nacimiento para habilitar la proyección de 52 años.";
  }

  // Mostrar resultados
  document.getElementById('cosmo-results').classList.remove('hidden');
}