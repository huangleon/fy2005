#include <ansi.h>
inherit ITEM;

#define MAX_ITEM 5

int do_put(object me, object obj, object dest);
int do_get(object me, object ob, object env);   //modified

void create()
{
        set_name("��ľ���", ({ "big mugui"}) );        // �����id�б���������������ʹ�õ���id!
        set_weight(300);
        set_max_encumbrance(80000);
        set("unit", "��");
        set("long", "һ�����Ϻú�ľ����ľ��\n");
        set("no_get",1);
        set("value", 0);
         seteuid(getuid());
}

int is_container() {return 1;}

/*
int reset_item_list(object dest)
{
        object room = environment(),obj,*inv;
        mapping item_list,item;
        mapping list,tlist;
        int i,j;
        inv = all_inventory(dest);
        i = sizeof(inv);
        room->delete("item_list");
        for (j=0;j<i ;j++ )
        {
                obj = inv[j];
                list = (mapping)obj->query_entire_dbase();
                tlist = (mapping)obj->query_entire_temp_dbase();

                        item =
                        ([
                                "item_basename": base_name(obj),
                                "data":list,
                                "temp_data":tlist,
                                "item_name": obj->query("name"),
                                "item_id": obj->parse_command_id_list(),
                                "amount": obj->query_amount(),
                        ]);
                room->set("item_list/"+(j+1),item);
        }
        room->save();
        return 1;
}

void init()
{
        add_action("do_putitem","put");
        add_action("do_getitem","get");
}


int do_getitem(string arg)
{
        object me = this_player(),env=this_object();
        string from, item;
        object obj, *inv,  obj2;
        object *my_inv, my_item;
        int i, j, amount, num;
        string arg1, from1;

        if( !arg ) return notify_fail("��Ҫ����ʲ�ᶫ����\n");
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɣ�\n");

// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1
        if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) {
                if (num==0 || num ==1)
                        return notify_fail("���ػ���ʹ��get xxx from xxx 0/1��\n");
        }

        if( sscanf(arg, "%s from %s", arg, from)!=2 )
                return 0;
                // ��������getָ���
        if (present(from,environment(me)) != env)
                return 0;

        
        // Check if a certain amount is specified.
        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("����û������������\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "���ܱ��ֿ����ߡ�\n");
                if( amount < 1 )
                        return notify_fail("�����ĸ���������һ����\n");
                if( amount > obj->query_amount() ) {
                        return notify_fail("����û��������" + obj->name() + "��\n");
                } else if(amount == (int)obj->query_amount()) {
                        return do_get(me, obj, env);    //modified
                } else {
                        obj->set_amount( (int)obj->query_amount() - amount );
                        obj2 = new(base_name(obj));
                        obj2->set_amount(amount);
                        obj2->move(me);         //modified
                        // Counting precise amount costs more time.
                        if( me->is_fighting() ) me->start_busy(3);
                        return do_get(me, obj2, env);   //modified
                }
        }

        // Check if we are making a quick get.
        if(arg=="all") {
                if( me->is_fighting() ) 
                        return notify_fail("�㻹��ս���У�ֻ��һ����һ����\n");
                if( !env->query_max_encumbrance() )     return notify_fail("�ǲ���������\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("������û���κζ�����\n");
                
        //      15 sec corpse loot protection. Only killer/self can loot the corpse.    
                if (env->query("allow_to_loot")) {
                        if (env->query("death_time")+15 > time()) {
                                if ( member_array( me,env->query("allow_to_loot")) == -1
                                        && env->query("victim_name")!= me->query("name"))
                                                return notify_fail("�����ڻ������������������\n");
                        }
                }
        
                for(i=0; i<sizeof(inv); i++) {
                        
                        if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
                                || inv[i]->query("no_get") || inv[i]->query("lore")) continue;
                        
                        if (inv[i]->query("allow_to_loot")) {
                        if (inv[i]->query("death_time")+15 > time()) {
                                if ( member_array( me,inv[i]->query("allow_to_loot")) == -1
                                        && inv[i]->query("victim_name")!= me->query("name"))
                                                return notify_fail("�����ڻ������������������\n");
                                }
                        }
                        do_get(me, inv[i], env);        //modified
                }
                write("Ok��\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry")))
                return notify_fail("�㸽��û������������\n");

        if( obj->query("no_get") )
                return notify_fail("��������ò�������\n");

//      lore item, you can only own one in your inventory at a time
        if ( obj->query("lore")) {
                my_inv = all_inventory(me);
                for(j=0;j<sizeof(my_inv);j++){
                        my_item = my_inv[j];
                        if(obj->query("name")==my_item->query("name")
                                && my_item->query("lore"))
                        return notify_fail("�������������ֻ����һ����\n");
                        }
        }

//      15 sec corpse loot protection. Only killer/self can loot the corpse.    
        
        if (env->query("allow_to_loot")) {
                if (env->query("death_time")+15 > time()) {
                        if ( member_array( me,env->query("allow_to_loot")) == -1
                                && env->query("victim_name")!= me->query("name"))
                                return notify_fail("�����ڻ������������������\n");
                }
        }
        if (obj->query("allow_to_loot")) {
                if (obj->query("death_time")+15 > time()) {
                        if ( member_array( me,obj->query("allow_to_loot")) == -1
                                && obj->query("victim_name")!= me->query("name"))
                                return notify_fail("�����ڻ������������������\n");
                }
        }
        
        return do_get(me, obj, env);    //modified
}


int do_get(object me, object obj,object env)    //modified
{
        object old_env, *enemy;
        int equipped;
        object target;
        string  prep;

        target = me;
        if( !obj ) return 0;
        old_env = env;  //modified
        if( obj->is_character()  && !obj->is_corpse()) {
                return notify_fail("�㲻�ܱ������\n");
                // If we try to save someone from combat, take the risk :P
        } else {
                if( obj->query("no_get") ) return 0;
        }

        if( obj->query("equipped") ) equipped = 1;
        if( obj->query("yes_carry")) target = environment(me);
        if( obj->move(target) ) {
                if((int)obj->query("no_transfer")){
                        obj->set("no_get",1);
                        obj->set("no_drop",1)
                
                reset_item_list(this_object())
                if(me->is_fighting())
                        me->start_busy(1)
                if( obj->is_character()  && !obj->query("yes_carry")
                        message_vision( "$N��$n�����������ڱ��ϡ�\n", me, obj )
                else 
                        if(old_env==environment(me)) prep =  "����"
                        else if(old_env->is_character()) prep =  "��" + old_env->name() + "����" + (equipped? "����" : "�ѳ�")
                        else switch( old_env->query("prep") ) 
                                case "on"
                                        prep = "��" + old_env->name() + "������"
                                        break
                                case "under"
                                        prep = "��" + old_env->name() + "���ó�"
                                        break
                                case "behind"
                                        prep = "��" + old_env->name() + "���ó�"
                                        break
                                case "inside"
                                        prep = "��" + old_env->name() + "���ó�"
                                        break
                                default
                                        prep = "��" + old_env->name() + "���ó�"
                                        break
                        }
                        message_vision( sprintf("$N%sһ%s$n��\n", prep
                                obj->query("unit")), me, obj )
                
                return 1
        
        else return 0
int do_putitem(string arg
        object me = this_player(),dest=this_object()
        string target, item
        object obj, *inv, obj2
        int i, amount
        if(!arg) return notify_fail("��Ҫ��ʲ�� [2;37;0m0mͳ����ɽ���(/d/huangshan/guangming.c)�������ھ�Ҫ�����ˣ�����happen��1��

 [2;37;0m���ˣ�����happen��1��

 [2;37;0m��\n")
        if (present(target,environment(me)) != dest
                return 0
       
        if(sscanf(item, "%d %s", amount, item)==2) 
                if( !objectp(obj = present(item, me)) 
                        return notify_fail("������û������������\n")
                if( !obj->query_amount() 
                        return notify_fail( obj->name() + "���ܱ��ֿ���\n")
                if( amount < 1 
                        return notify_fail("����������������һ����\n")
                if( amount > obj->query_amount() 
                        return notify_fail("��û��������" + obj->name() + "��\n")
                else if( amount == (int)obj->query_amount() 
                        return do_put(me, obj, dest)
                else 
                                obj2 = new(base_name(obj))
                                obj2->set_amount(amount)
                                if (do_put(me, obj2, dest)
                                
                                        obj->set_amount( (int)obj->query_amount() - amount )
                                        return 1
                                }              
                                if (obj2) destruct(obj2)
                                return 0
                
        
        if(item=="all"
        
                inv = all_inventory(me)
                for(i=0; i<sizeof(inv); i++
                        if( inv[i] != dest  && !inv[i]->query("no_drop"))
                        do_put(me, inv[i], dest)
                write("Ok.\n")
                return 1
        
        if(!objectp(obj = present(item, me))
                return notify_fail("������û������������\n")
        return do_put(me, obj, dest)
int do_put(object me, object obj, object dest
        string prep
        int container_size
       
        if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore")
                return notify_fail("�㲻������ô����\n")
        if (obj->is_container()
                return notify_fail("�㲻�ܰ�����������һ�������\n");
        if( obj == dest
                        return notify_fail("�㲻������ô����\n")
       
        if(dest->is_closed()
                return notify_fail("��Ҫ�Ȱ�" + dest->name() + "�򿪡�\n")
        container_size = dest->query("size") ? dest->query("size") : MAX_ITEM
        // �����б�����ͨputָ���˲���return notify_fail�� annie 08.200
        // <-------------------------------------------------------------
        if(sizeof(all_inventory(dest)) >= container_size
        
                tell_object(me,dest->name() + "�������ֻ�ܷ�" + chinese_number(container_size) 
                                "����Ʒ��\n")
                return 1
        
        if (obj->query("no_stock")
        
                tell_object(me,"���������޷���š�\n")
                return 1
        
        if (obj->query("value") < 4)    // �޷��䵱�Ķ�������Ϊ��unique item�
        
                tell_object(me,"������������ֵ����Ǯ��û��С�ı���ı�Ҫ��\n")
                return 1
        
        // --------------------------------------------------------------
       
        switch((string)dest->query("prep")) 
                case "on" 
                        prep = "����" + dest->name() + "��"
                        break
                case "under" 
                        prep = "����" + dest->name() + "��"
                        break
                case "behind" 
                        prep = "����" + dest->name() + "����"
                        break
                case "insdie" 
                        prep = "�Ž�" + dest->name() + "����"
                        break
                default 
                        prep = "�Ž�" + dest->name() + "����"
                        break
        
        if( obj->move(dest) ) 
                message_vision( sprintf("$N��һ%s%s%s��\n"
                        obj->query("unit"), obj->name(), prep)
                        me )
                if(obj->query("no_drop") || obj->query("no_get")|| obj->query("lore")
                        dest->add("no_give",1)
                reset_item_list(dest)
                return 1
        
        else return 0
/
���������������X�
���������������U�t�
���������������U���t�
���������������U�����t�
���������������U�������
���������������^�k�k�k�
��������������- FengYun - �����
������������annie 08.200
������dancing_faery@hotmail.co
*
chat ���޸����Խ�����
chat ϣ�������Թ���..
chat ����uploda
chat ����upload

update /obj/item/box.c

chat lag .....................
chat* slogan

*/