// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER2;

void create()
{
	set_inherit_room(__DIR__"maze-room");

	set_maze_long(4,4,7);
	set_maze_spacing(10);
	set_maze_refresh(0);

	set_entry_dir("down");

	set_link_entry_dir("out");
	set_link_entry_room(__DIR__"bottom17");
	set_link_entry_room_x(-10);
	set_link_entry_room_y(40);
	set_link_entry_room_z(900);
	
	set_link_exit_dir("up");
	set_link_exit_room(__DIR__"bottom18");

	set_entry_short(MAG"��������"NOR);
	set_entry_desc(@LONG
����������������Ĺ⾰���ྶͥ��ֻ������ǣ�ᣬ�����ܲ�������ķ�
�����̻ң�һ����������䣬�����������̨��֮�ϣ�����������ģ�������
����̴ľ��¥����������������ȥ��
LONG
);

	set_exit_short(CYN"��������"NOR);
	set_exit_desc(@LONG
����������������Ĺ⾰���ྶͥ��ֻ������ǣ�ᣬ�����ܲ�������ķ�
�����̻ң�һ����������䣬�����������̨��֮�ϡ�¥������������������
������ȥ���Ѿ��ɼ���϶��͸���������գ���֪�����ﴫ��һ��һ�������ĵ�
�������������������
LONG
);

	set_maze_room_short(MAG"������"NOR);
	set_maze_room_desc(@LONG
����������������Ĺ⾰���ྶͥ��ֻ������ǣ�ᣬ�����ܲ�������ķ�
�����̻ң�һ����������䣬�����������̨��֮�ϣ�����������ģ�������
����̴ľ��¥����������������ȥ��
LONG
);

//	set_outdoors(1);

}

/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/
