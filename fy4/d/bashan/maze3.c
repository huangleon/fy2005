// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER2;

void create()
{
	set_inherit_room(__DIR__"maze3-room");

	set_maze_long(5,5,3);
	set_maze_spacing(10);
	set_maze_refresh(0);

	set_entry_dir("down");

	set_link_entry_dir("down");
	set_link_entry_room(__DIR__"churoom_2");
	set_link_entry_room_x(-40);
	set_link_entry_room_y(40);
	set_link_entry_room_z(120);
	
	set_link_exit_dir("up");
	set_link_exit_room(__DIR__"edge");

	set_entry_short(CYN"�ִ�֦��"NOR);
	set_entry_desc(@LONG
�����ڲ����ľ�Ĵִ�֦��֮�ϣ��㲻�ɸ�̾��컯֮�棬��������������һ
Ƭ���֣�Ϊ��ɽ��������ṩ��һ���������Ի�Խ����Ȼ���ϡ�֦��ǰ�����ż�
�����۴�ϸ�����������������ǽ�ʵ���������������ǰ����
LONG
);

	set_exit_short(CYN"�ִ�֦��"NOR);
	set_exit_desc(@LONG
�����ڲ����ľ�Ĵִ�֦��֮�ϣ��㲻�ɸ�̾��컯֮�棬��������������һ
Ƭ���֣�Ϊ��ɽ��������ṩ��һ���������Ի�Խ����Ȼ���ϡ�֦��ǰ�����ż�
�����۴�ϸ�����������������ǽ�ʵ���������������ǰ����
LONG
);

	set_maze_room_short(MAG"��ɽ�ż�"NOR);
	set_maze_room_desc(@LONG
����ʯ��������Ȼ���ڰ�ɽ֮�ϡ���ͷ��ȥ��ֻ����ɽ���곱ʪ�������
����ɽ���Ϸ�ʴ�������ӿ����ݵ�С������ɽ�����ĺ�ʯ���������ѣ���ȥ���ǹ�
��Ҥ������Զ�������ǽ��������겻ɢ��������ï�������赲������ǰ������
һ�����������������������ĺۼ���
LONG
);

	set_outdoors(1);

}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
