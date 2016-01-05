// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","�ֱ�");			// 	Edge
		room->set("long",@LONG
����һƬï�ܵ������֣����з�����������Ӣ�ͷף�һ�㵭���ı�������� 
����Ĳ��㣬�����ڿ���֮�С��ʲ����е�������һɢ���������°��ף�ż����һ 
�����������������Գ��ľ����������С·�ѱ��仨������������ó�һ˿�ۼ��� 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","�ּ�");
		room->set("long",@LONG
�����һ����������ۺ�ɫ�Ļ��������ڿ�����ÿһ������������Ũ����ˣ� 
��ʱ��һ�����㲻�������ؿ�������ʹ������Ҳ���������������ӿ��µ��ǣ��� 
�ܾ���������������ͷ����Ũ�صĻ�������Լ���ֳ������̹���������
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","����");
		room->set("long",@LONG
����һת��ԭ�����������֣����Ƶ��˸���·��������ʱ��·����ֻ���ޱ��� 
�����һ��κ��һ��֡�Ũ��Խ��Խ�أ���ͬҹɫ����һ�㣬�����һ����·���� 
��ǰ����Զ����ߵ����ҡҷƮ��
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","����");
		room->set("long",@LONG
�����ƽ����·�����ֹ���Ĺ����쳾ӭ������������ǻ������Ҳ��ǻ������� 
ȥ��·��ǰ����·��������ʧ�ڻ���֮�У����˻�����ǰ����·������·���㲻�� 
��ͷ�亹���δ���¡�
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (y<=4) {
		room->set("objects",([				
			__DIR__"npc/ty-redfox": 	!random(3),
			__DIR__"npc/ty-snake":		!random(2),
			__DIR__"npc/ty-redfox2":	!random(3),
			__DIR__"npc/ty-boss":		!random(3),
		]));		
	} else 	if (y<=7) {
		room->set("objects",([				
			__DIR__"npc/ty-rabbit": 	!random(3),
			__DIR__"npc/ty-butterfly":	!random(3),
			__DIR__"npc/ty-redfox":		!random(6),
			__DIR__"npc/ty-redfox2":	!random(5),
			__DIR__"npc/ty-snake":		!random(3),
			__DIR__"npc/ty-boss":		!random(3),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/ty-deer":	 	!random(8),
			__DIR__"npc/ty-rabbit": 	!random(2),
			__DIR__"npc/ty-butterfly":	!random(2),
			__DIR__"npc/ty-redfox":		!random(5),
		]));		
	}
	room->setup();
}


