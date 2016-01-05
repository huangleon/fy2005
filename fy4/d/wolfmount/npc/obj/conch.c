#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"��"HIB"��"HIG"��"HIY"��"NOR,({ "conch shell","conch","shell" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "wood");
                set("long", "һ���������磬�߲ʰ�쵵ĺ��ݣ�����Դ�������\n");
                set("desc_ext", "blow conch shell");
        }
	::init_item();
}

void init()
{
       	if (environment()== this_player())
       		add_action("do_blow", "blow");
}

int do_blow(string arg)
{
        object ob;
        
        if (!arg)	return 0;
        ob = present(arg, this_player());
        if (!ob || ob!= this_object())	return 0;
        	
		if (this_player()->is_busy())
		{
			tell_object(this_player(),"��������æ��\n");
			return 1;
		}	

        if ( this_player()->query("force") < 50 )
        {
        	tell_object(this_player(),"���������㣬������ѽ����Ҫ�������ڣ�����\n");
        	return 1;
        }
        else if ( this_player()->query("force_factor") < 40 )
        {
        	message_vision("$N���������ӣ����Ų��Ӵ���"+ this_object()->name() + "����ʲô����Ҳû�С�\n" , this_player() );
        	tell_object(this_player(),"������Ҫ40�������enforce 40��\n");
        	return 1;
        }
        
        	message_vision("$N���ᴵ����" + this_object()->name() + "����ʱ���ཡ����졣��\n", this_player() );
        	this_player()->add("force",-40);
        	this_player()->perform_busy(1);
        	environment(this_player())->conch_notify();
        	return 1;
        
}
