// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�˱������������������ѧ�����г����⡰[33m���ֹ���[32m��ʫ�����塰[33m������־��
��[32m����������������ѧ���������ڣ�ϰ��֮�˵����޲�עĿ������ϸ�о�������
�������ɡ����˶����֣����Ǵ����á�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"bei3",
  "east" : __DIR__"ciyun",
]));
        set("objects", ([
                BOOKS"skill/dabei_50" : 1,
                BOOKS"unarmed_50a" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",20);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
}
