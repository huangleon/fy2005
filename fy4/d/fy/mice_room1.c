// Ascii mice from http://www.geocities.com/SouthBeach/Marina/4942/ascii.htm

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
    
[37m     
         (,).-"  ".			
        /',  _ (   )________,
        `^'"` """"'`
[0m

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		  "down" : __DIR__"mice_room2",
	]));
	set("item_desc",([
        	"down":	"������ڹ�¡��ʲôҲ�����壬ֻ��ЩϤϤ�����Ķ�����\n",
        ]));
        
        set("objects", ([
        	__DIR__"npc/s_mice" : 1,
         ]) );
        
	set("coor/x",200);
	set("coor/y",-60);
	set("coor/z",-10);
	setup();
}


int valid_leave(object me, string arg){
	object roach;
	
	if (arg == "down") {
		if (roach = present("mouse",this_object()))
			return notify_fail(roach->name()+"��ݺݵ�����������\n");
		else
			message_vision("$N�����ڵ���������ȥ��������\n",me);
			return 1;
	}
	return ::valid_leave(me,arg);
}


        