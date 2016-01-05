// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));
	
 	if (exit_number>2) {				// 	Crossroad
		room->set("pos","crossroad");
		room->set("short",CYN"��������"NOR);
		room->set("long",@LONG
��֦�������������Ĵ�ʵ������������������һ�����ѵ�����������������
�����ű��ϵļ�����ľ��ֻҪ�Լ�С�Ĳ�����ʵ���������Ϳ��Բ���ֱ��������
�粢�еĴִ�֦�ɡ�
LONG
	);
	} else 	if (exit_number==1) {		//	Deadend
		room->set("pos","deadend");
		room->set("short",CYN"���ɾ�ͷ"NOR);
		room->set("long",@LONG
��������㾪��ȥ·�Ѿ����ִ��֦��������ϸ�����ŵ�����Ҳ�Ѿ�ҡҡ��
׹��ʵ��û�п����ٳ���һ���˵����������ܲ�Զ��������һ���ָ�б�ң�ȴ�뿪
��ֱ��������Զ���������ð��׹���Σ�ճ��Է�Ծ����ֻ�л�ͷһ;��
LONG
	);		
	} else {							//	Normal description
		room->set("pos","normal");
		room->set("short",CYN"�ִ�֦��"NOR);
		room->set("long",@LONG
�����ڲ����ľ�Ĵִ�֦��֮�ϣ��㲻�ɸ�̾��컯֮�棬��������������һ
Ƭ���֣�Ϊ��ɽ��������ṩ��һ���������Ի�Խ����Ȼ���ϡ�֦��ǰ�����ż�
�����۴�ϸ�����������������ǽ�ʵ���������������ǰ����
LONG
	);
	}
	
}

void 	setup_npc_obj(object room,int length, int width, int x, int y)
{
		object icecave;
		int boss_x,boss_y;

	room->setup();

		icecave = new(__DIR__"mazenpc/maze2_guard"+(random(8)+1));
		icecave->move(room);

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
