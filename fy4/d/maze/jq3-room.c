// Sinny-silencer@fy4 workgroup 
#include <ansi.h>
inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short",YEL"������"NOR);			// 	Edge
		room->set("long",@LONG
��֮�ڴ�����˶��ԣ����������������Ϊ��Ҫ�������в���������ƶ���� 
�������ƣ���һ���������֣�����ʲô�˲��ᱻ�򵹵��أ���������Ľ��ͺ����� 
�����������Ů���ˣ�������Ϊ��һ�������� 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		switch (random(2)) {
			case 0:	room->set("short",CYN"������"NOR);
				room->set("long",@LONG
���ĸ����������˼�������Ȼ������ͼ�������ϣ������������Ϲٽ��Ҳ�� 
���⣬�������ǵ�ʿ�����ڵ�������֮��Ҳ�����ĵã��������Ҳ�����˴Ӻ� 
�����Ѽ��������鵤��ҩ��Ӧ�о��С� 
LONG
	);
				break;
			case 1: room->set("short",HIY"������"NOR);
				room->set("long",@LONG
������������Ϊ������������������Ϊ���������Ϲ����û��˭���ᱻǮ 
�򶯣�û��ʲô�ǲ����򲻵��ģ�û��ʲô�ǲ����ò����ġ���Ǯ��֮������ڼ 
Ϊ��Ǯ֮���Ȼ�����Խ�ǮΪ�ף��Բ���Ϊ֮������ 
LONG
	);
		}

	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short",MAG"ϲ����"NOR);
		room->set("long",@LONG
������ϲ�ã�ÿ���˶�����һ��֮����һ��֮�á�����һ�У����Ϲٽ��� 
������ɾ����������µ�һ�������롣 
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		switch (random(2)) {
			case 0: room->set("short",GRN"������"NOR);
				room->set("long",@LONG
��Ǯ��֮�����ڳ�Ұ�������������Ϊ��Ǯ��ｨ���Ӵ�ļ�Ժ���ĳ� 
�����������ų��ڵĵ�Ȩ����ٸ��������ҶԽ�Ǯ�������춯����Ϊ˭������ 
�����ͷ�������϶��Ͳ�������ڶ���ĳ�����
LONG
	);
				break;
			case 1: room->set("short",HIY"������"NOR);
				room->set("long",@LONG
�����ٻ�����Ȼ���Ϲ������һ������˵����׶�����Ϊ��������ܿܿ�� 
���У�����˭���ӵ����������ֵ��ջ���
LONG
	);
		}
	
	
	}
}

void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=20) {
		room->set("objects",([				
			__DIR__"npc/jq3-ass4": 		!random(5),
			__DIR__"npc/jq3-ass5": 		!random(5),
			__DIR__"npc/jq3-herald3": 	!random(8),
		]));		
	} else 	if (x>=10) {
		room->set("objects",([				
			__DIR__"npc/jq3-ass3": 		!random(5),
			__DIR__"npc/jq3-ass4": 		!random(5),
			__DIR__"npc/jq3-herald2": 	!random(8),
		]));		
	} else  {
		room->set("objects",([				
			__DIR__"npc/jq3-ass1": 		!random(5),
			__DIR__"npc/jq3-ass2": 		!random(5),
			__DIR__"npc/jq3-herald1": 	!random(8),
		]));		
	}
	room->setup();
}