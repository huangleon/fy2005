
inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
����ĺ������������������į��������ɫ�����һ�ֿ���������ĻҰ�ɫ��
ĮĮ��ɳ���ޱ��޼ʡ��ƺ���ԶҲ�߲���ͷ��һ����ȥ�������Ż�ɳ����ɳ����
�죻�ˣ�Ҳ�������ġ�  
LONG
        );
        set("exits", ([ 
		"southeast" : __DIR__"mfoot",
  		"northwest" : __DIR__"skyroad2",
	]));
        set("outdoors", "quicksand");

	set("coor/x",-1120);
	set("coor/y",100);
	set("coor/z",0);
	setup();
}
