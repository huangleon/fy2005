#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "�鷿");
    set("long", @LONG
һ��С�ݣ�ֻ��ǽ�Ϲ���������������ֻ��������Ҳ������ƽʱ�ѵ�һ����
���ָ������鼮��һ��������ʿ������һ���ֻ�����
LONG
    );
    set("exits", ([
		"north" : __DIR__"zoulang1",

    ]));
    set("objects", ([
		__DIR__"npc/wenshi": 1,
    
    ]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",-10);

	setup();

}

void reset() {
	string *item= ({"parry_50","literate_50b","move_60","skill/wuzheng-force_60"});
	object ob;
	
	:: reset();
	
	foreach (string x in item) 
	{
		ob = new(BOOKS+x);
		if (present(ob,this_object())) destruct(ob);
			else ob->move(this_object());
	}
}


