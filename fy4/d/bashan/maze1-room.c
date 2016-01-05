// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));

	switch (random(6))
	{
	case 0:
		room->set("short",CYN"����̤ѩ"NOR);
		room->set("long",@LONG

[1;36m   ����������       ̤������ѩ ��  ��  �� 

[1;37m�������˻�Ψ��м������α��ࡣ��븡��ǳ�������������
[2;37;0m
LONG
	);
		break;
	case 1:
		room->set("short",CYN"������Ȫ"NOR);
		room->set("long",@LONG

[1;32m   ����������       ��������Ȫ ��  ��  �� 

[1;36m�������b�b˭ߵ�ң���ҹ�߲��ࡣ����˼���ᣬ�串���Ȫ��
[2;37;0m
LONG
	);
		break;
	case 2:
		room->set("short",CYN"��������"NOR);
		room->set("long",@LONG

[1;37m   ����������       ��������ʫ ��  ��  �� 

[1;32m�������������ܯ�����໽��˼����ͷԧ�����������ʫ��
[2;37;0m
LONG
	);
		break;
	case 3:
		room->set("short",CYN"��������"NOR);
		room->set("long",@LONG

[1;33m   ����������       �á������� ��  ��  �� 

[1;31m��������Բ������ڰ�����֡����������ϣ���ذ�Ŀ�塣
[2;37;0m
LONG
	);
		break;
	case 4:
		room->set("short",CYN"��������"NOR);
		room->set("long",@LONG

[1;34m   ����������       �顡������ ��  ��  �� 

[1;33m��������������ϼ����������ѻ��ǳ�����Զ���������黨��
[2;37;0m
LONG
	);
		break;
	case 5:
		room->set("short",CYN"�����"NOR);
		room->set("long",@LONG

[1;31m   ����������       �ˡ������� ��  ��  �� 

[1;34m���������޳����̣������ˮ�ˡ�������������ָ��������
[2;37;0m
LONG
	);
		break;
	}
	
}



void 	setup_npc_obj(object room,int length, int width, int x, int y)
{
		object icecave;
		int boss_x,boss_y;
		icecave = load_object(__DIR__"enterance");
		icecave->generate_maze1();
		boss_x = icecave->query("maze1/boss_x");
		boss_y = icecave->query("maze1/boss_y");


		room->set("objects",([				
			__DIR__"mazenpc/maze"+(random(2)+2)+"_guard"+(random(8)+1):1,
		]));		

	if (x == boss_x && y == boss_y)
		room->set("objects",([				
			__DIR__"npc/jat":1,
		]));		


		set("x",x);
		set("y",y);
		room->set("exits/up",__DIR__"enterance");
		room->set("perma_exist",1);
		set("perma_exist",1);

		room->setup();
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
