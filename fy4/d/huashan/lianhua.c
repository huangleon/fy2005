#include <ansi.h>
inherit ROOM;
string dan();

void create()
{
        set("short", "������");
        set("long", @LONG
����������о�ʯ���������������ֽ������塣ɽ��Ϊһ��������ʯ����Ȼ��
�ɡ���������ǧ�̣��Ƶ�����أ��䶸��Ρ�롢����ͦ��֮���ǻ�ɽɽ��֮����
��˹��˳��ѻ�ɽ����ɽ�����Ͽ������Կ������������������������������¡�
LONG
        );
    	set("exits", ([ 
        "eastdown" : __DIR__"shanlu2",
	    "southwest" : __DIR__"sheshen",
	    "southeast" : __DIR__"zhenyue",
	    "northdown" : __DIR__"fupi",
	]));
	set("objects", ([
		__DIR__"npc/zahuo" : 1,
	]));
/*    	set("item_desc", ([
    		"����" : (: dan :),
    		"danzi" : (: dan :),
    	]));*/
	set("item_bamboo", 1);    
    	set("outdoors", "huashan");
    	set("release_hawk",1);
	set("coor/x",-75);
	set("coor/y",-55);
	set("coor/z",40);
	setup();
}

/*
string dan(){
	object me;
	me = this_player();
	if(!present("dan fan", this_object())){
		return "ʲô��\n";
	}
	tell_object(me, "������ͷ�����������˸�ɫ��Ʒ����ʳƷ����֬����Ӧ�о��С�\n");
	if(query("item_bamboo")){
		tell_object(me, "�ⵣ���ڵ��ϣ��Ա���һ����ɵ���Ͳ������������磩��\n");
	}	
	return "";
}
*/