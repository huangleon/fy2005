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
				set("value",2000);
                set("material", "wood");
                set("long", "һ���������磬��ʰ�쵵ĺ��ݣ�����Դ�������\n");
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
        	
        if ( this_player()->query("force") < 50 )
        {
        	message_vision("$N�������㣬���ܴ�"+ this_object()->name() + "��\n" , this_player() );
        	return 1;
        }
        else if ( this_player()->query("force_factor") < 40 )
        {
        	message_vision("$N���������ӣ����Ų��Ӵ���"+ this_object()->name() + "����ʲô����Ҳû�С�\n" , this_player() );
        	tell_object(this_player(),"������Ҫ40�������enforce 40��\n");
        	return 1;
        }
        else
        {
        	message_vision("$N���ᴵ����" + this_object()->name() + "����ʱ���ཡ����졣��\n", this_player() );
        	message_vision("$N������ס��" + this_object()->name() + "�����������ɣ����" + this_object()->name() + "���ֶ�����\n", this_player() );
			this_player()->set_temp("annie/wolf_conch",1);
			destruct(this_object());
        	return 1;
        }	
}


