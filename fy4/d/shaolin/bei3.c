// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ�б���Ϊ�����鷨�������飬��������ǧ���ɣ�������������ġ�[33m��һɽ[32m��
Ϊ�����ϡ��֮�������ࡰ[33m��ʮ���帳[32m����Ҳ�ڱ����������������б�����߹�
�ͼ�ֵ��һ�С����������Ǳ��ֵ����һ�С�
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"bei4",
  		"southwest" : __DIR__"yingbi",
	]));
        set("objects", ([
                BOOKS"skill/zen_50" : 1,
                BOOKS"skill/buddhism_50" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}
