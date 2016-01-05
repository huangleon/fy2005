// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","������");			// 	Edge
		room->set("long",@LONG
�Ϲ��뾣�������˾�����������֮�ˣ������ü�������ʱ��ǰ��ѵ����е��� 
����֮��������Ҳʱ�������������µ��������޴��Ͷ����Ǯ����������ø��� 
���������佲��������������ǰ�����ֱ�޷��������ﾹ�ڵ��£��ƻ��յ������� 
����磬��Բ����֮�������ͭ�Ÿߴ����ɡ�һ��˶��Ľ��ҿ������ɷ����һ 
�����䡱�֡� 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","�ǻ���");
		room->set("long",@LONG
���˽Գ��ף��ǻ��������������������е����á��ǻ��á�������û�л��ǵ� 
ͷ�ԣ����ݵ����֣�����һ�ȵĵ�ʶ�������ǻ��ã��������ǻ�����ͷ���������� 
ʱ������������Ȫ���Ϲ�һ���������ѣ�����Ψ�ǻ�ʼ֪��ʧ���ɵ�ʧ�����ɰܡ� 
������ʿ����ѵ��������������ǻ������ܸ��ַǳ��������ܵĿ��顣�������֣� 
��ʶ������Ӧ�о��С�
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","ɱ¾��");
		room->set("long",@LONG
��Ǯ���¾�Ϊ�ܲ��������ʿ����������֮ɫ�䡣����ÿһ�����Ӷ��������� 
�о���ɱ¾�õĿ��飬�������������ԡѪ��ս��û���ĸ������ܻ����߳������� 
�������ò�ͬ��ɱ¾����·����ȥ·������ɱ��Ѫ·���ȴ���ģ�ֻ����·��
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","ƶ����");
		room->set("long",@LONG
�Ϲ�����Ҿ�ƶ��������ĸ�����Ժ���ӣ������˼�����ƶ����������Ǯ��� 
Ϊ������һ�����İ�ᣬ���еļ����벻�ס���ʹ���ս�Ǯ�︻�ɵй����Ϲ�Ҳ�� 
�ſ���ɮ������������µ��ӽ��������������޷��������й���ƶ��һ�أ��� 
�������������ԻὫ�����ʦ�š�
LONG
	);
	}
}

void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=8) {
		room->set("objects",([				
			__DIR__"npc/jq1-guard2": 	!random(10),
			__DIR__"npc/jq1-guard3":	!random(10),
			__DIR__"npc/jq1-hyguard":	!random(5),
			__DIR__"npc/jq1-scorpion":	!random(10),
		]));		
	} else 	if (x>=4) {
		room->set("objects",([				
			__DIR__"npc/jq1-guard1": 	random(80)<50,
			__DIR__"npc/jq1-guard2":	!random(10),
			__DIR__"npc/jq1-scorpion":	!random(6),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/jq1-guard2": 	!random(10),
			__DIR__"npc/jq1-scorpion": 	random(80)<50,
			__DIR__"npc/jq1-guard1":	!random(10),
		]));		
	}
	room->setup();
}


