inherit ROOM;
void create()
{
        set("short", "������������");
        set("long", @LONG
����������Ԫ�����������������ֵĳ�������İ�����������ʷ�ƾö�����
�������������й�ǧ�����ʷ���������ν��ʮ�ﳤ�֣������Ƽ��������Ͼ��Ǵ�
��������������һ�������������֡�
LONG
        );
        set("exits", ([ 
	  "north" : __DIR__"tulu",
	  "south" : __DIR__"bazha",
	]));
        set("objects", ([
        	__DIR__"npc/gate_soldier" : 2,
        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",0);
	set("coor/y",30);
	set("coor/z",0);
	setup();

}


int valid_leave(object me, string dir)
{
	object *inv;
	object ob;
	int i;
	if( userp(me) && ob=present("garrison", this_object()))
	{
		if( dir == "south" )	{
			inv = all_inventory(me);
			for(i=0; i<sizeof(inv); i++)	{
				if((int)(inv[i]->query("weapon_prop")) && (int)(inv[i]->query("equipped")))
					return notify_fail(ob->name()+"����ȵ��������ֱֳ�����ǣ�\n");	
			}
		}
	
        	if ( dir == "south" && me->is_naked())  {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"����üͷ˵��С���ӹ���ƨ��������ȥ����ʲô���ӣ�\n\n");
			else
				return notify_fail(ob->name()+"����ȵ�������������ҡ���У��ɺ���ͳ����\n");
		}
        	
               	return 1;
	}
	else
		return 1;
				
}
