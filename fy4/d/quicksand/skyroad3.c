
inherit ROOM;

void create()
{
        set("short", "����·");
        set("long", @LONG
����ĺ������������������į��������ɫ�����һ�ֿ���������ĻҰ�ɫ��
ĮĮ��ɳ���ޱ��޼ʡ��ƺ���ԶҲ�߲���ͷ��һ����ȥ�������Ż�ɳ����ɳ����
�죻�ˣ�Ҳ�������ġ�Զ����ȥ���ѿɿ���һ�㵭��������������  
LONG
        );
        set("exits", ([ 
  "southwest" : __DIR__"skyroad2",
  "northwest"  : AREA_XINJIANG"heimiao",
]));
        set("outdoors", "quicksand");

	set("coor/x",-900);
	set("coor/y",500);
	set("coor/z",0);
	setup();
}
