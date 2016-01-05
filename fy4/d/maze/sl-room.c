// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","�����");			// 	Edge
		room->set("long",@LONG
���˰˲�����Ĵ�λ������֮�У���һ��Ϊɳ����������������Ů����ʱ���� 
�ȷ�Ĳ����˵��������ɽǰ��תΪ�����ַ�֮�ࡣ���ɷ�֮ʱ��Ϊ�����˲������� 
�����ĺ����ڣ�������צ������һ���� 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","Ǭ���ŵ�");
		room->set("long",@LONG
Ǭ������һ�ֲ��Ծ��⡢ֻѰ������Ϊ���������Ƿ��̵��͵�����֮һ���� 
�Ϸ���Ũ������������Ǭ���š���������Ϊ�����Ī�⡱֮�⣬�����Լ������׽ 
�������е���Ҳ���ع��죬���˲���������
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		switch (random(3)) {
			case 0:		
				room->set("pos","deadend");
				room->set("short","�����޵�");
				room->set("long",@LONG
���������ߣ��м���Ů��������Ϊ�С����ӱ��ꡢִ���ƶʡ�����Ĳ��˵ 
����˵�����������������Ҳ˵����˵�������������Ĳ��˵������ʮ�ߵ�Ʒ 
������������ƫ�ֶ�һƷ����˵��ʮ�˵�Ʒ�������Ƕ��۾���ʮ�壺������������ 
���˹ʣ������ڷ�ν�����졣��Ϊ˵�����ڡ���ν�����ڣ���Ϊ˵һ����˵���� 
�У�ν�����У���˵һ�¡��� 
LONG
				);		
			case 1:
				room->set("pos","deadend");
				room->set("short","Ħ�����ȵ�");
				room->set("long",@LONG
Ħ������Ϊ����֮��������ͷ�����������������������Ħ�������������ϣ� 
�������ģ��������£����������ɡ� 
LONG
				);		
			case 2:
				room->set("pos","deadend");
				room->set("short","�����޵�");
				room->set("long",@LONG
������������Ϊ���˷��ˡ��������ˣ�ͷ���ǣ����Գ�Ϊ���˷��ˡ������ڸ� 
�裬�ǵ��͵����񡣵��н����޷������裬����ƮƮ��Ī�����
LONG
				);		
		}
	
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","��¥�޵�");
		room->set("long",@LONG
��¥��Ϊһ���񣬳���ׯ�ϱ�ɫ��ͷ��������Ϊ�����飬�����������࣬���� 
Ϊʳ������һ�������С���������գ������¶����޷��ٳԣ��������·����ߴΣ� 
�������ɽ�������ա���Ϊ��һ������Ϊʳ����ڻ�������࣬����ʱ���� 
�Է١�������ȥ��ֻ��һ�ģ�����������ɫ��
LONG
	);
	}
}


void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=14) {
		room->set("objects",([				
			__DIR__"npc/sl-monk3": 		!random(5),
			__DIR__"npc/sl-monk3a":		!random(5),
			__DIR__"npc/sl-monk3b":		!random(5),
			__DIR__"npc/sl-sentry": 	!random(10),
		]));		
	} else 	if (x>=7) {
		room->set("objects",([				
			__DIR__"npc/sl-monk2": 		!random(5),
			__DIR__"npc/sl-monk2a":		!random(5),
			__DIR__"npc/sl-monk2b":		!random(5),
			__DIR__"npc/sl-sentry": 	!random(10),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/sl-monk1": 		!random(5),
			__DIR__"npc/sl-monk1a":		!random(5),
			__DIR__"npc/sl-monk1b":		!random(5),
			__DIR__"npc/sl-sentry": 	!random(10),
		]));		
	}
	room->setup();
}
