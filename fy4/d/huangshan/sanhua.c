// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
    set("short", "ɢ����");
    set("long", @LONG
ɢ������һ��ȣ����з��Ͳβ�ʼܷ壬����ʯ�ȹ�ʯ������䣬Զ�۷���
���֣����˹�ʯ���ɡ�ÿ������֮��������ʢ�������Ƿ����ƽ�������Ůɢ������
��һƬ����ȵء�������������Ĺ�ʯ�α�������
LONG
        );
	set("exits", ([ 
		"south" : __DIR__"guangming",
  		"northwest" : __DIR__"shisun",
  		"north" : __DIR__"mengbi",
		"west" : __DIR__"shizi",
	]));
    set("outdoors", "huangshan");
	set("coor/x",-90);
	set("coor/y",0);
	set("coor/z",30);
	setup();

}

