// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɮ��");
        set("long", @LONG
һ���������ڣ��粻�����ܵĵ�[33m����[32m������󣩣�Ҳ�벻�����Ǽ���������
�����Ķ������ֵİ�����ߴ����ֵ�аͽ���ܱ��ؽ�����Ķ��ǷǷ�֮�ˣ���ϧƷ
�в��ˣ��ĳ���ÿ������Ҫ���̽�վ����Ե㻯�����в������ɴ˸Ķ���ƣ��
�����
LONG
        );
        set("exits", ([ 
  		"north" : __DIR__"laon",
  		"south" : __DIR__"laos",
  		"west": __DIR__"lao",
  		"east" : __DIR__"laoe",
		]));
        set("objects", ([
                __DIR__"obj/mantou" : 2,
                __DIR__"obj/purewater" : 2,
				BOOKS"skill/daode_50" : 1,
       	]) );
		set("NONPC", 1);
		set("coor/x",20);
		set("coor/y",120);
		set("coor/z",20);
		setup();
}

void init()
{
	if(this_player()->query_skill("daode",1) < 10)
		this_player()->set("startroom", base_name(this_object()));

}
