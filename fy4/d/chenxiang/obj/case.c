inherit ITEM;

void create()
{
        set_name("����", ({ "iron case","case"}) );
        set_weight(500); 
		set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "��");
                set("long", "һ���޴�����䡣\n");
                set("value", 1);
        }
	::init_item();
}

int is_container() { return 1; }

void init()
{
        add_action("do_open","open");
}


void reset(){

	if (!random(10))	set_temp("been_get",0);

}

int do_open(string arg)
{
        object cash,map;
        object guard;       
        
	if(arg!="iron case"&&arg!="����"&&arg!="case") return 0;
	else
	{
		if(guard = present("dragon dizi",environment(this_object())))
			if (guard->query("name")=="���������")
        		{
        		message_vision("$N��$n�ȵ�����Ϲ�������ϰ��Ҫ�������\n", guard, this_player());
        		return 1;
        		}
       		message_vision("$N������ĸ���...\n",this_player());
        	if(query_temp("been_get"))
                return notify_fail("������䣬������տ���Ҳ��ʲôҲû�С�\n");
        	set_temp("been_get",1);
    		tell_object(this_player(),"�㷢��������һ�ŵ�ͼ������æ����������\n");
    		this_player()->set_temp("marks/longlife_getmap",1);
			map=new(__DIR__"map");
			map->move(this_player());
			return 1;
	}
}
