
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������Ķ���Щ��ɳĮ�ıر���Ʒ�����գ�ˮ������ʳ���޾ߣ��Լ�һЩ��
�����飬���������ã���ʱ�����õĶ�������������˶���������õĻ�ɫ���г�
����������·�˵��۾�������Ҳ������·�ϵ����ˣ�����ɫ�ͺ��������ƻ���һ����
·�˵���Ȥ�����ǵĻ�����ǵ���Ȥȴ��·�˵�Ǯ����
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"fair",
 		"west": __DIR__"house",
 		"east": __DIR__"yizhan",
 		"south": __DIR__"jadestore",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
        	__DIR__"npc/trader2": 	1,
        	__DIR__"npc/trader3":   1,
                
        ]) );

	set("coor/x",-1030);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}

