// Sinny-silencer@fy4 workgroup 

inherit ROOM;


void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
	set("no_fly",1);
	
	if ( x == length-1 || y == width-1 || x = 0 || y == 0) {
		room->set("pos","edge");
		room->set("short","��Ѫ��");			// 	Edge
		room->set("long",@LONG
����һ����������������ճճ�����ź�ɫ�����£��ƺ���Ѫ���ƺ����ͣ���
��ʬ��ɢ�䣬����ɫ���׹�����������Щ���ǰ�е�·���˳����� 
LONG
	);
	} else 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short","������");
		room->set("long",@LONG
�����������Σ������Ķ��Ǳ�ҩ����ƣ�ɥʧ���ǵĽ������֣�����߳����ƣ� 
�εȷ������������Ϊ���¿��ܣ������޾��������ٳ�ʮ�֣����ֲ�����ָ��һ 
��һ����ͬ��������ķ�����ʱ����������Ǻ����˻�С�
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short","�ݸ���");
		room->set("long",@LONG
�ݸ��ѷζ��˳�������Ѫ�����أ�ʬ����ɽ���ڽ�Ǯ���������ȫ�������� 
���ǣ����������ɣ������ɻ���ȥ��������ȥ��Ψһ���������ñ�����������Ϊֻ 
���������ˣ��������ʵ��⣬����������Ѫ�����п���ȡů��ë���������������� 
�������ģ���һ�����ǽ����ж���ĸ��֡�
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short","�����");
		room->set("long",@LONG
������߮�Ź»�Ұ���ķ��ˣ�û�����գ�û�иٳ���û��֪����û����ʶ�� 
ֻ��һ��һ���ɱ¾��ֻ�е���������������������ʱ��ÿһ���Ļ�Ż�֪�� 
����Ҫ��������һ���µ�ʳ���ˮ�Ͳ������Ѷ����ġ����������衻������ 
Ҳֻ��һ�����ڣ�û����֪���Ǹ���̫ͬ���Ͼ�����ɷ���ǵ���������ζ��� 
�ģ�Ī�ǣ����������ˣ�
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y){
		
	int exit_number;
	exit_number= sizeof(room->query("exits"));
	
	if (x>=14) {
		room->set("objects",([				
			__DIR__"npc/jq2-dead7": 	!random(5),
			__DIR__"npc/jq2-dead8": 	!random(5),
			__DIR__"npc/jq2-dead9": 	!random(5),
			__DIR__"npc/jq2-guard": 	!random(10),
			__DIR__"npc/jq2-boss": 		!random(10),
		]));		
	} else 	if (x>=7) {
		room->set("objects",([				
			__DIR__"npc/jq2-dead4": 	!random(5),
			__DIR__"npc/jq2-dead5": 	!random(5),
			__DIR__"npc/jq2-dead6": 	!random(5),
			__DIR__"npc/jq2-guard": 	!random(10),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"npc/jq2-dead1": 	!random(5),
			__DIR__"npc/jq2-dead2": 	!random(5),
			__DIR__"npc/jq2-dead3": 	!random(5),
			__DIR__"npc/jq2-guard": 	!random(10),
		]));		
	}
	room->setup();
}

