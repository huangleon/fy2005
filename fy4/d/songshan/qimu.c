// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��ĸʯ");
        set("long", @LONG
���سǲ�Զ���㵽��ĸʯ���ഫ������ĸ�����������������ˮ�������ң�̫
��֮���ͨ��������Ϳɽ�������ͷ���һ��ɽʯ��·�����������ܿ�ɽ�����Ӽ�
�������ܵĴ������Ź��Ȼ�Ϊʯͷ����ʱ�����ף������ʯʹ�ޣ���Ȼʯ��
������������ʯ��Ӵ˽�������ĸʯ����������ɽ�������澰��
LONG
        );
        set("exits", ([ 
  "northeast" : __DIR__"shaoshi",
  "southeast" : AREA_QUICKSAND"dengfeng",
]));
        set("objects", ([
                __DIR__"npc/yumo" : 1,
       ]) );
        set("outdoors", "songshan");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
