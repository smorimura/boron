  "camera: context [\n"
  "    orient: none\n"
  "    position: none\n"
  "    viewport: 0,0,640,480\n"
  "    fov: 65.0\n"
  "    near: 0.1\n"
  "    far: 10.0\n"
  "]\n"
  "ortho-cam: make camera [\n"
  "    fov: 'ortho\n"
  "    near: -100.0\n"
  "    far: 100.0\n"
  "]\n"
  "gui-style-proto: context [\n"
  "    texture:\n"
  "    tex-size:\n"
  "    control-font:\n"
  "    title-font:\n"
  "    edit-font:\n"
  "    list-font:\n"
  "    label:\n"
  "    area:\n"
  "    start-dl:\n"
  "    window-margin:\n"
  "    window:\n"
  "    button-size:\n"
  "    button-up:\n"
  "    button-down:\n"
  "    button-hover:\n"
  "    checkbox-size:\n"
  "    checkbox-up:\n"
  "    checkbox-down:\n"
  "    label-dl:\n"
  "    editor:\n"
  "    editor-active:\n"
  "    editor-cursor:\n"
  "    list-header:\n"
  "    list-item:\n"
  "    list-item-selected:\n"
  "    none\n"
  "]\n"
  "animation: context [\n"
  "    value: none\n"
  "    curve: none\n"
  "    period: 1.0\n"
  "    time: 0.0\n"
  "    behavior: 1\n"
  "]\n"
  "ease-in: [\n"
  "    0.0 0.0\n"
  "    0.15 0.003375\n"
  "    0.3 0.027\n"
  "    0.5 0.125\n"
  "    0.7 0.343\n"
  "    0.85 0.614125\n"
  "    1.0 1.0\n"
  "]\n"
  "ease-out: [\n"
  "    0.0 0.0\n"
  "    0.15 0.385875\n"
  "    0.3 0.657\n"
  "    0.5 0.875\n"
  "    0.7 0.973\n"
  "    0.85 0.996625\n"
  "    1.0 1.0\n"
  "]\n"
  "draw-list: func [blk] [make draw-prog! blk]\n"
  "switch environs/os [\n"
  "    Linux [mouse-lb: 0x100 mouse-mb: 0x200 mouse-rb: 0x400]\n"
  "    [mouse-lb: 1 mouse-mb: 3 mouse-rb: 2]\n"
  "]\n"
  "load-shader: func [file] [make shader! load file]\n"
  "load-texture: func [file /mipmap /clamp | spec] [\n"
  "    spec: file: load-png file\n"
  "    if mipmap [spec: [file 'mipmap]]\n"
  "    if clamp [spec: [file 'linear 'clamp]]\n"
  "    make texture! spec\n"
  "]\n"
  "audio-sample: context [\n"
  "    sample-format:\n"
  "    rate:\n"
  "    data: none\n"
  "]\n"
  "load-wav: func [file | csize format channels srate bps sdata] [\n"
  "    parse read file [\n"
  "        little-endian\n"
  "        \"RIFF\" u32 \"WAVEfmt \"\n"
  "        csize: u32\n"
  "        format: u16\n"
  "        channels: u16\n"
  "        srate: u32 u32 u16\n"
  "        bps: u16\n"
  "        \"data\"\n"
  "        csize: u32\n"
  "        copy sdata csize\n"
  "    ]\n"
  "    if ne? format 1 [\n"
  "        error \"WAV data is compressed\"\n"
  "    ]\n"
  "    format: make coord! [bps channels 0]\n"
  "    make audio-sample copy [\n"
  "        sample-format: format\n"
  "        rate: srate\n"
  "        data: sdata\n"
  "    ]\n"
  "]\n"
  "unit-matrix:\n"
  "#[1.0 0.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 0.0 1.0 0.0 0.0 0.0 0.0 1.0]\n"
  "make-matrix: func [pos] [poke copy unit-matrix 13 pos]\n"
