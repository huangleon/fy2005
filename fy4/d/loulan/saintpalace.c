
inherit ROOM;

void create()
{
        set("short", "ʥ��");
        set("long", @LONG
�����ഫ¥����������������һ������ı�������������ܲ��������İ�
�أ��ഫ�������ܲγ�����أ����˱��������ɵ�¥����ʥ�ˣ��ܴ���¥��ȫ����
���������������¥���˺ľٹ�֮�˶�����������������ʥ����ʥ���ݷ���ͬ
���հ����ׯ�ϣ���ʯ���ϲʻ渡����������������Ϻ����ȼ���ʺ��ëձ����
����ʯ���ϣ�ԭ��������¥��ʥŮ�ĸ�̨�ϸ߸߷����Ž��Ρ�
LONG
        );

        set("exits", ([ 
		"west" : __DIR__"weststrt",
		"east" : __DIR__"eaststrt",
		"south" : __DIR__"southstrt3",
		"north" : __DIR__"northstrt3",
	]));
        set("objects", ([
                __DIR__"npc/chai" : 1,
	]) );
        set("indoors", "loulan");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}