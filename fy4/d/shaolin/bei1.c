// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�Ɱ����������Ϊ�����ĵ�����[33m�����������ʫ�鱮[32m����������׫�ģ���֪��
���飬���������̶������ͱ��£��������飬�����پ�������������ͨ�����˵���
ѧ�����ೢ�޲����ڡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bei2",
]));
        set("objects", ([
                BOOKS"skill/puti-steps_50" : 1,
		__DIR__"npc/pupil" :2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-20);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
