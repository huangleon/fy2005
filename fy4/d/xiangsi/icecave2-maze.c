// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER;

void create()
{
	set_inherit_room(__DIR__"icecave2-room");

	set_maze_long(8,10);
	set_maze_spacing(10);
	set_maze_refresh(0);

	set_entry_dir("north");

	set_link_entry_dir("north");
	set_link_entry_room(__DIR__"icecave-exit");
	set_link_entry_room_x(-20);
	set_link_entry_room_y(-120);
	set_link_entry_room_z(30);
	
	set_link_exit_dir("south");
	set_link_exit_room(__DIR__"icecave-exit");	// û��ʵ�ʳ��ڣ����Թ��������

	set_entry_short(HIR BLK"����С��"NOR);
	set_entry_desc(@LONG
С��������н������߳߸��µı����ϣ���Ҫ��ʱ����ĵ��������µı��⣬
���Ǳ����ϰ�͹��ƽ�ı��ӱ���������ʱ���ű����ı����ѿɿ������ڣ�ǰ��ȴ
����ټ��ı�ʯ��סȥ·����Խ��ǰ�У�����ľ���������Խ���������е�������
���������������𲻶���΢����â֮�ϡ�
LONG
);

	set_exit_short(HIR BLK"����С��"NOR);
	set_exit_desc(@LONG
С��������н������߳߸��µı����ϣ���Ҫ��ʱ����ĵ��������µı��⣬
���Ǳ����ϰ�͹��ƽ�ı��ӱ���������ʱ���ű����ı����ѿɿ������ڣ�ǰ��ȴ
����ټ��ı�ʯ��סȥ·����Խ��ǰ�У�����ľ���������Խ���������е�������
���������������𲻶���΢����â֮�ϡ�
LONG
);

	set_maze_room_short(HIR BLK"����С��"NOR);
	set_maze_room_desc(@LONG
С��������н������߳߸��µı����ϣ���Ҫ��ʱ����ĵ��������µı��⣬
���Ǳ����ϰ�͹��ƽ�ı��ӱ���������ʱ���ű����ı����ѿɿ������ڣ�ǰ��ȴ
����ټ��ı�ʯ��סȥ·����Խ��ǰ�У�����ľ���������Խ���������е�������
���������������𲻶���΢����â֮�ϡ�
LONG
);

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
