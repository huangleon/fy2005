
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
  "southeast" : __DIR__"skyroad1",
  "northeast" : __DIR__"skyroad3",
]));
        set("outdoors", "quicksand");

	set("coor/x",-1130);
	set("coor/y",300);
	set("coor/z",0);
	setup();
}
