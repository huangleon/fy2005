inherit ROOM;

void create()
{
        set("short", "ɳ��");
        set("long", @LONG
������ȥ��ֻ�л�ɳ���ޱ��޼ʣ������޾��Ļ�ɳ��û��ˮ��û��������Ҳ
û��ϣ�����˴���Զ��ϡ��ʱ����û��ɳ�����в�Ᵽ�ɳ���Ϻ�Ȼʬ���ݺᣬѪ
��δ�ɡ���Ϊ�ɲ�����Ƶ����ɳ����������ɳ�ڷ籩�о��裬Ψ�������뼹��[33m��[32m
���г�·�����Ǻ���Ϲ������һ����Ҳ��һ���ߵó�ȥ��
LONG
        );
        set("exits", ([ 
		"south" : 	__DIR__"greenland",
		"west" : 	__DIR__"desert6",
		"northeast" : 	__DIR__"mirage",
		"east" : 	__DIR__"desert8",
	]));
        set("outdoors", "loulan");
	set("coor/x",-1085);
	set("coor/y",50);
	set("coor/z",0);
	setup();
}
