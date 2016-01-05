// bamboo_pipe.c

inherit ITEM;

void create()
{
        set_name("���",({ "bamboo pipe", "pipe" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "bamboo");
                set("long", "һ��Լ���߶೤����ܣ������������С�ף�Ҳ������������ࡣ\n");
                set("desc_ext", "blow bamboo pipe");
        }
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

        message_vision("$N����һ��" + name() + "���ཱུش���������\n",this_player() );
        environment(this_player())->pipe_notify();

        return 1;
}
