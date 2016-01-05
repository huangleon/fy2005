// ������ҩ��ʵ����

#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
        set_name("ҩ�ݵ�", ({ "herb field"}) ); // �����id�б���������������ʹ�õ���id!
        set_weight(30000);
        set_max_encumbrance(100);
        set("unit", "Ƭ");
        set("desc", "һƬҩ�ݵأ���˵�������ӣ�ֻ��ˮ�����ͻ᳤����ҩ��\n");
        set("no_get",1);
        set("no_sell",1);
        set("no_drop",1);
        set("no_stack",1);
        set("no_reset",1);
        set("item_type","q");
        set("outdoors",1);
        set("size",1);
set("tax",30);
set("score_tax",3);
        set("value", 300000);
        seteuid(getuid());
}

int is_container(){     return 1;}

void init()
{
	::init();
	if (environment() != this_player())
			add_action("do_water","water");
}

int do_putitem(string arg)
{
        object me = this_player(),dest=this_object();
        string target, item;
        object obj, *inv, obj2;
        int i, amount;

        if(!arg) return notify_fail("��Ҫ��ʲ�ᶫ���Ž����\n");

        if( sscanf(arg, "%s in %s", item, target)!=2 )
                return notify_fail("��Ҫ��˭ʲ�ᶫ����\n");

        if (present(target,environment(me)) != dest)
                return 0;
        
        write("�뱣�ֻ�����࣬��Ҫ��������ҩ�ݵ����Ҷ���\n");
        return 1;
}


int reset_item_list(object dest)
{
	return 1;
}

int do_water(string arg)
{
        int     s, amount, da,req;
        object me = this_player(),env=environment(me),ob=this_object(),skin,herb;
        object * inv;
        string target,what;
        int i,water;

        string *water_type = ({
        "�׺�","��������","����ɫ����ˮ","΢��ľ�ˮ","�ɶ�����","ɽ������","��ˮ","Ư��һЩ������ˮ","��ˮ",
        });
        if (!env->is_owner(me->query("id")))
                return notify_fail("����������ֻ�����˲���ʹ�á�\n");
        if (!arg)
                return 0;
        if (sscanf(arg,"%s in %s",what,target) != 2)
                return 0;
        if (present(target,env) != ob)
                return 0;
        if (!skin =     present(what,me))
                return notify_fail("��Ҫ��ʲô�����ࣿ\n");
        if (!skin->query("liquid/type"))
                return notify_fail( skin->name() +"������װˮ��>\"<\n");
        if (!skin->query("liquid/remaining"))
                return notify_fail( skin->name() +"�ǿյġ�\n");

        inv = all_inventory(ob);
        if (sizeof(inv))
                return notify_fail( "ҩ�ݵ�����Щ������С�ĳ����ˡ�\n");

        if (skin->query("liquid/name") == "�����¶")
        {
                if (!ob->query("used"))
                        return notify_fail( "ҩ�ݵ�ʮ�ָɾ�������Ҫ���ҳ�ϴ��\n");
                if (me->is_fighting() || me->is_busy()) return 1;
                skin->add("liquid/remaining",-2-random(5));
                if (skin->query("liquid/remaining") < 0)
                        skin->set("liquid/remaining",0);
                message_vision(CYN"\n$NС���������"+skin->name()+"�е�"+skin->query("liquid/name")+"��ϴ��һ��ҩ�ݵء�\n", me);
                set("used",0);
                return 1;
        }
        else
        {
                if (ob->query("used"))
                        return notify_fail( "���ٴ�ʹ��ҩ�ݵ�֮ǰ������Ҫ�������¶ϴȥ��������ա�\n");
        }


        if (me->is_fighting() || me->is_busy()) return 1;
        me->perform_busy(2);

        skin->add("liquid/remaining",-2-random(5));
        if (skin->query("liquid/remaining") < 0)
                skin->set("liquid/remaining",0);

        message_vision(CYN"\n$NС������Ľ�"+skin->name()+"�е�һЩ"+skin->query("liquid/name")+"������ҩ�ݵ��ϡ�\n", me);

        if (query("last_irrigated") + 300 > time())
        {
                // ��̫��ˮ....������
                set("herb_type",0);
                set("herb_time",0);
                set("last_irrigated",0);
                set("used",1);  // ��Ҫ�����
                herb = new("/obj/medicine/herb_failed.c");
                herb->move(ob);
                message_vision(CYN"ֻ��$Nһ������������ˮ���̫�࣬ҩ���Ѿ������õ��ˡ�\n", me);
                return 1;
        }

        if (query("last_irrigated")>1 && query("last_irrigated") + 900 < time())
        {
                // ̫��û�й�....������������
                set("herb_type",0);
                set("herb_time",0);
                set("last_irrigated",0);
                set("used",1);  // ��Ҫ�����
                herb = new("/obj/medicine/cactus.c");
                herb->move(ob);
                message_vision(CYN"ֻ��$Nһ�������������ƺ�������ʲô��ֵĶ���������\n", me);
                return 1;
        }

        set("last_irrigated",time());
        add("herb_time",1);
        for (i=0; i<sizeof(water_type);i++ )
                if (skin->query("liquid/name") == water_type[i])
                        water=i+1;
        switch (query("herb_time"))
        {
        case 1:
                add("herb_type",water);
                break;
        case 2:
                add("herb_type",water*100);
                break;
        case 3:
                add("herb_type",water*10);
        
                switch (query("herb_type"))
                {
                        case 129:
                                herb = new("/obj/medicine/herb_f2.c");
                                req=9;
                                break;
                        case 247:
                                herb = new("/obj/medicine/herb_f3.c");
                                req=8;
                                break;
                        case 832:
                                herb = new("/obj/medicine/herb_e2.c");
                                req=7;
                                break;
                        case 571:
                                herb = new("/obj/medicine/herb_d12.c");
                                req=6;
                                break;
                        case 768:
                                herb = new("/obj/medicine/herb_d22.c");
                                req=5;
                                break;
                        case 496:
                                herb = new("/obj/medicine/herb_d32.c");
                                req=4;
                                break;
                        case 985:
                                herb = new("/obj/medicine/herb_e1.c");
                                req=3;
                                break;
                        case 613:
                                herb = new("/obj/medicine/herb_c1.c");
                                req=2;
                                break;
                        case 354:
                                herb = new("/obj/medicine/herb_c2.c");
                                req=1;
                                break;
                        default:
                                herb = new("/obj/medicine/mushroom.c");
                                req=0;
                                break;
                }
//                if (me->query("marks/herb_knowledge") < req)
				if (me->query_skill("herb",1) < req*20+20)
                        herb = new("/obj/medicine/mushroom.c");

                herb->set_amount(1);
				herb->set("value",0);
				herb->set("base_value",0);
                set("herb_type",0);
                set("herb_time",0);
                set("last_irrigated",0);
                set("used",1);  // ��Ҫ�����
                herb->move(ob);
                message_vision(CYN"\n��$N�ľ��������£����ﳤ����һЩ"+herb->name()+"������\n", me);
                break;
        }
        return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/

