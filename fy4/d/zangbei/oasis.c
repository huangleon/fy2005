
inherit ROOM;

void create()
{
        set("short", "�Ŷ�̲");
        set("long", @LONG
һ����ˬ��΢���������������һ���ϱ�����������Լ����ʮ�ף�����
Ȫˮ�丣���Ϊ��������βС����ˮ����߮���������������̲ݷҷ����������к�
���Ĺ�Ĺ�������ʸ������˳ƴ˵�Ϊ�Ŷ�̲����������ǧ���������Ψһ���Բ�
����ˮ�ĵط����������ǰ���ˮ��װ���ɣ�
LONG
        );
        set("exits", ([ 
	  	"south" : __DIR__"yangguan",
			]));
	set("objects", ([
		__DIR__"npc/camel" : 1,
		__DIR__"npc/camel2" : 1,
		__DIR__"npc/waterwoman" : 1,
		
	]));
	set("item_desc",([
		"tomb":"��Щ��Ĺ�Ѿ�����ͷ�ˣ�������������䱦Ҳ��Ͳ�֪ȥ��\n",
		"��Ĺ":	"��Щ��Ĺ�Ѿ�����ͷ�ˣ�������������䱦Ҳ��Ͳ�֪ȥ��\n",
		"�": "Ȫˮ�丣����Щˮ�ɡ�\n",
	]));
	set("resource/water",1);
        set("liquid", ([
        "container": "��",
        "name":	"�Ŷ�̲ˮ",
       	]));
        set("outdoors", "zangbei");
        set("map","zbeast");

        set("coor/x",0);
	set("coor/y",20);
	set("coor/z",0);
	setup();
}

void dig_notify()
{
     object me;
     me = this_player();
     tell_object(me,"��������Ϊ������Ϊ����Ȼ����Ҳ��������ȱ��֮�£�\n");
}
