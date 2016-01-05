// pipe.c

inherit ITEM;

void create()
{
        set_name("ͭ��",({ "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "steel");
                set("long", "һ��Լ����೤��ͭ�ڡ�\n");
                set("desc_ext", "blow copper pipe");
        }
	::init_item();
}

void init()
{
        if(environment()==this_player())
        	add_action("do_blow", "blow");
}

int do_blow(string arg)
{
        object ob;
        
        if (!arg)	return 0;
        ob = present(arg, this_player());
        if (!ob || ob!= this_object())	return 0;
        	
        message_vision("$N����һ��" + this_object()->name() + "����һ����\n", this_player() );
        environment(this_player())->pipe_notify();
        return 1;
}
