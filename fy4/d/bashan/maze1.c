// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit VRM_SERVER;

void create()
{
    set_inherit_room(__DIR__"maze1-room");

    set_maze_long(6,6);
    set_maze_spacing(1);
    set_maze_refresh(0);

    set_entry_dir("east");

    set_link_entry_dir("east");
    set_link_entry_room(__DIR__"enterance");
    set_link_entry_room_x(0);
    set_link_entry_room_y(0);
    set_link_entry_room_z(0);

    set_link_exit_dir("west");
    set_link_exit_room(__DIR__"jadegate");


    set_entry_short(MAG"�ŷ�����"NOR);
    set_entry_desc(@LONG
������ȥ������С��ɽ����������Ī��Ĺŷ�ߡ�վ�ڶ��ڿ�ȥ��ֻ�����ҷ�
�⣬ò�����ˣ������������Է�����ӳ���������˵�����ڽ��������֮��������
���󷨣�����������ɫ����������һ����ߣ���ֻ�����ֻ����������������
���ᣬ�����ʧ������֮�С�
LONG
    );

    set_exit_short(MAG"�ŷ�ߺ�"NOR);
    set_exit_desc(@LONG
�߳����������������ҵĹŷ�ߣ��㲻�����������һ�ڳ����������������
�ֻ����亹˲����ʪ�������������ߺ���һ��խС��ͨ·��ͨ·����������
վ�������ѿ��Կ���������һ����ɫʯ�š�
LONG
    );

    set_maze_room_short(MAG"�ŷ��"NOR);
    set_maze_room_desc(@LONG
������ȥ������С��ɽ����������Ī��Ĺŷ�ߡ�վ�ڶ��ڿ�ȥ��ֻ�����ҷ�
�⣬ò�����ˣ������������Է�����ӳ���������˵�����ڽ��������֮��������
���󷨣�����������ɫ����������һ����ߣ���ֻ�����ֻ����������������
���ᣬ�����ʧ������֮�С�
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
