// silencer@fy4 workgroup ������֮ľ��

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","���");			// 	Edge
		room->set("long",@LONG
����Ƕ�Ѩ�ı�Ե����ΧҪ������࣬�������Һ�ɫ�ģ�������ż������Щ��
����ľ�ܺ��ƹ����裬��Ȼ������������������ϸ�������Ͽ�����ϡ�����Ա��ϳ�
һЩ����������֣��ƺ��ǵ�ʿ����ʱ���ķ��䡣
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","���");
		room->set("long",@LONG
��ǰ�Ķ�Ѩ��Ȼ�ֳ��˲����ÿһ�����Ǻ�����ģ���һ���ſ���Ѫ���ڵ�
�����ڵȴ���̽���ߡ����º�Ȼ�ߵ��������ã�������һ���������������⣬Ȼ��
�Ѿ�û�л�ͷ��·�ˣ�������Թ�Ҳ����ס��ÿһ������֮�͡�
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","���");
		room->set("long",@LONG
��������˵���ڣ�ײ��ʯ����ŷ�������ԭ��������·��������ʯ����ε�
����ˮ����ھ�����������˸���ս�����ǿ�Щ���ҳ�·�ɡ�
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","���");
		room->set("long",@LONG
һ���������ɽ�����ڳ�����һ���������ס������ʯ����������̦޺������
����ʪ�ֻ�����ʯ���ƺ����˹�����ģ������ܵ�ʯ�������ܿ�������ĺۼ�����
�ﲻʱ������ֵ��춯���ƺ��������ڿ��������ƺ���Ұ�޵Ĵ�Ϣ��������������
�ţ�������Щ��ǵ�ζ����
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (y<=8) {
		room->set("objects",([				
			__DIR__"npc/cv-beast3":	 	!random(5),
			__DIR__"npc/cv-bug3": 		!random(5),
			__DIR__"npc/cv-devil3":		!random(5),
			__DIR__"npc/cv-boss":		!random(10),
		]));		
	} else 	if (y<=15) {
		room->set("objects",([				
			__DIR__"npc/cv-beast2":	 	!random(5),
			__DIR__"npc/cv-bug2": 		!random(5),
			__DIR__"npc/cv-bug1": 		!random(3),
			__DIR__"npc/cv-beast1":		!random(3),
			__DIR__"npc/cv-devil1":		!random(8),
			__DIR__"npc/cv-devil2":		!random(8),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/cv-devil1":		!random(3),
			__DIR__"npc/cv-devil2":		!random(3),
			__DIR__"npc/cv-bug1": 		!random(6),
			__DIR__"npc/cv-beast1":		!random(6),
		]));		
	}
	room->setup();
}


void	init(){
	
}

