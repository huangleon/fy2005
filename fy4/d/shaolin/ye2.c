// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "Ҵ��");
        set("long", @LONG
����һ��С�ţ�ƽ�����ǹ��ŵģ��������������ƥ�������Դ�����ֱ������
�����ǽ����������ӳ������һ����ζ�������ȥ���ǳ�������������������
���У��������ӿɴӴ˴������֣� 
LONG
        );
        set("exits", ([ 
  "eastdown" : __DIR__"shandan",
  "northeast" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"npc/monk4" : 2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",-10);
	setup();
}


int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
	        if( !me->query_temp("shaolin") 
	        	&& me->query("class") != "shaolin" 
	        	&& dir == "northeast" 
	        	&& ob=present("shaolin monk", this_object()))
        	{
                	inv = all_inventory(me);
                	for(i=0; i<sizeof(inv); i++)
                        	if(inv[i]->query("shaolin_cloth") && (int)inv[i]->query("equipped"))
	                        	return 1;
                	return notify_fail(ob->name()+"���㹰�ֵ���û����ɽ�ƣ������ֵ��Ӳ������ڣ���\n");
        	}
        	return 1;
        }
        else 
        	return 1;
}