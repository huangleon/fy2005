// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "���ɽׯ");
        set("long", @LONG
�߹����۵�ʯ�ݣ����ڵ�����·�ľ�ͷ������ɽ��֮��������˽������Ǿ���
���漣��ƫƫ���һ����ͨ������ȴ����һ���ǳ����������֣������ɽׯ������
ǰ��һ��С¥���Ѿ����������ĸ��ڵ׽�Ƕ���֣�������С¥��
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"xingxing",
  "northdown" : __DIR__"huoyan",
]));
	set("outdoors","shenshui");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
