// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short",HIR BLK"����֮��"NOR);
		room->set("long",@LONG
����̹ǵĺ����ڱ�������������ʱ�������ķ�Ӷ����ӹ������л�����Щ��
��������΢������������ǰ�����Ǻ��ˣ�����Ҳ�ǲ���ı��ң�����Ҳ�Ǵ�����ѩ
�����Ƶľ����ŵ���ѳֲ������ķ����ҡ�
LONG
	);
	} else 	if (exit_number==1) {				//	Deadend
		room->set("pos","deadend");
		room->set("short",HIR BLK"����֮ǰ"NOR);
		room->set("long",@LONG
�ƹ�֧�Ŷ����ĺ���б������Ҫǰ�У�ȴ��������������ĺڰ��ﾹҲ���ˣ�
�����Ż�ߡ�����������������һ��������ȥ��ȴ�����ǲ�����һ�¾޴�ļ��
���ڣ���ס��������·�������ϵ�ӳ�ŵ��ƺ������Ӱ�ӣ�ȴ���ƺ������������
��Ц��
LONG
	);		
	} else {						//	Normal description
		room->set("pos","normal");
		room->set("short",HIR BLK"����С��"NOR);
		room->set("long",@LONG
С��������н������߳߸��µı����ϣ���Ҫ��ʱ����ĵ��������µı��⣬
���Ǳ����ϰ�͹��ƽ�ı��ӱ���������ʱ���ű����ı����ѿɿ������ڣ�ǰ��ȴ
����ټ��ı�ʯ��סȥ·����Խ��ǰ�У�����ľ���������Խ���������е�������
���������������𲻶���΢����â֮�ϡ�
LONG
	);
	}
}



void 	setup_npc_obj(object room,int length, int width, int x, int y)
{
		object icecave;
		int boss_x,boss_y;
		icecave = load_object(__DIR__"icecave");
		icecave->generate_maze();
		boss_x = icecave->query("icecave/boss_x");
		boss_y = icecave->query("icecave/boss_y");

// ��һ����һ����ף�ѩ������
// 5   70 30
// 10  90 10
// 2 
// �^�[�a�X�T�U�g�d�p�m�j
/*
�X�T�j�T�[10
�Uһ�U���U8
�U��U�רU6
�d�T�m�T�g4
�U������U2
�^�T�T�T�a0
0 2 4 6 8

һ������24�� x < 4 && y >= 4
��������24�� x >= 4 && y >= 4
�������32�� y < 4

������ܹ�����*doubt
*faint ȡ���Թ��Ƚ�ƽ��?! �찡.....99%�Թ�ͨ·����������leh..

*/

	if (x < 4 && y >= 4) {
		room->set("objects",([				
			__DIR__"mazenpc/po":		random(80) < 54,
			__DIR__"mazenpc/pe":		!random(13),
			__DIR__"mazenpc/shade":		!random(13),
		]));		
	} else 	if (x >= 4 && y >= 4) {
		room->set("objects",([				
			__DIR__"mazenpc/pe":		random(80) < 54,
			__DIR__"mazenpc/po":		!random(13),
			__DIR__"mazenpc/shade":		!random(13),
		]));		
	}else  {
		room->set("objects",([				
			__DIR__"mazenpc/po":		random(80) < 30,
			__DIR__"mazenpc/pe":		random(80) < 30,
			__DIR__"mazenpc/shade":		random(32) < 10,
		]));		
	}

	if (x == boss_x && y == boss_y)
	{
		room->delete("objects");
		room->set("boss_room",4);			// 1/4���ʡ�
		room->set("ph",__DIR__"mazenpc/efreet");
		room->set("boss",__DIR__"mazenpc/whitefox");
		room->set("refresh",2);				// maze ����� 15min ����boss/ph
	}

	room->setup();
}

int ph_here()
{
	object env,*inv;
	int i;
	env = this_object();
	inv = all_inventory(env);
	for (i=0;i<sizeof(inv) ; i++)
		if (inv[i]->query("real_boss") || inv[i]->query("real_ph"))	// ��Ȼ��
			return 1;

	return 0;
}

void reset()
{
	object npc;
	if (query("boss_room"))
	{
		set("pos","boss");
		set("short",WHT"����֮��"NOR);
		set("long",@LONG
�е����ԭ����խ�ı���ȴͻ��������ȥ���ó���һ��ʮ��ƺ��Ŀյأ���
��Χ�Ŀ�����Ҳ���Ǳȷ��Ÿ��Ӵ̹Ǳ������յ���Ʈ���ż������ĵ�ӫ���׻�һ
������������ѹ�����������˷��������в��ɵ�����һ���������Ƶĺ��⣬����
�߳��������亹��
LONG
	);

		if (!ph_here())
			add("refresh",-1);
		if (query("refresh") == 0)
		{
			if (!random(query("boss_room")))	
			{
				npc = new(query("boss"));
				npc->move(this_object());
				set("refresh",12);			// Boss����3Сʱˢ�¡�
			}
			else
			{
				npc = new(query("ph"));
				npc->move(this_object());
				set("refresh",4);			// ����1Сʱˢ�¡�
			}
		}
	}
	::reset();
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
