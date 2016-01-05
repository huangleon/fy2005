#include <ansi.h>
inherit ITEM;

#define MAX_ITEM 5

int do_put(object me, object obj, object dest);
int do_get(object me, object ob, object env);   //modified

void create()
{
        set_name("ºìÄ¾´ó¹ñ", ({ "big mugui"}) );        // ÈÃÕâ¸öidÓĞ±ğÓÚÆäËû¶«Î÷¡£²»Ê¹ÓÃµ¥×Öid!
        set_weight(300);
        set_max_encumbrance(80000);
        set("unit", "¸ö");
        set("long", "Ò»¸öÓÃÉÏºÃºìÄ¾×÷µÄÄ¾¹ñ¡£\n");
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

        if( !arg ) return notify_fail("ÄãÒª¼ñÆğÊ²÷á¶«Î÷£¿\n");
        if( me->is_busy() )
                return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¡\n");

// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1
        if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) {
                if (num==0 || num ==1)
                        return notify_fail("²»±Ø»ò²»ÄÜÊ¹ÓÃget xxx from xxx 0/1¡£\n");
        }

        if( sscanf(arg, "%s from %s", arg, from)!=2 )
                return 0;
                // ¶ª¸øÕı³£getÖ¸Áî´¦Àí
        if (present(from,environment(me)) != env)
                return 0;

        
        // Check if a certain amount is specified.
        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                        return notify_fail("ÕâÀïÃ»ÓĞÕâÑù¶«Î÷¡£\n");
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "²»ÄÜ±»·Ö¿ªÄÃ×ß¡£\n");
                if( amount < 1 )
                        return notify_fail("¶«Î÷µÄ¸öÊıÖÁÉÙÊÇÒ»¸ö¡£\n");
                if( amount > obj->query_amount() ) {
                        return notify_fail("ÕâÀïÃ»ÓĞÄÇ÷á¶àµÄ" + obj->name() + "¡£\n");
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
                        return notify_fail("Äã»¹ÔÚÕ½¶·ÖĞ£¡Ö»ÄÜÒ»´ÎÄÃÒ»Ñù¡£\n");
                if( !env->query_max_encumbrance() )     return notify_fail("ÄÇ²»ÊÇÈİÆ÷¡£\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("ÄÇÀïÃæÃ»ÓĞÈÎºÎ¶«Î÷¡£\n");
                
        //      15 sec corpse loot protection. Only killer/self can loot the corpse.    
                if (env->query("allow_to_loot")) {
                        if (env->query("death_time")+15 > time()) {
                                if ( member_array( me,env->query("allow_to_loot")) == -1
                                        && env->query("victim_name")!= me->query("name"))
                                                return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
                        }
                }
        
                for(i=0; i<sizeof(inv); i++) {
                        
                        if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
                                || inv[i]->query("no_get") || inv[i]->query("lore")) continue;
                        
                        if (inv[i]->query("allow_to_loot")) {
                        if (inv[i]->query("death_time")+15 > time()) {
                                if ( member_array( me,inv[i]->query("allow_to_loot")) == -1
                                        && inv[i]->query("victim_name")!= me->query("name"))
                                                return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
                                }
                        }
                        do_get(me, inv[i], env);        //modified
                }
                write("Ok¡£\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry")))
                return notify_fail("Äã¸½½üÃ»ÓĞÕâÑù¶«Î÷¡£\n");

        if( obj->query("no_get") )
                return notify_fail("Õâ¸ö¶«Î÷ÄÃ²»ÆğÀ´¡£\n");

//      lore item, you can only own one in your inventory at a time
        if ( obj->query("lore")) {
                my_inv = all_inventory(me);
                for(j=0;j<sizeof(my_inv);j++){
                        my_item = my_inv[j];
                        if(obj->query("name")==my_item->query("name")
                                && my_item->query("lore"))
                        return notify_fail("ÕâÑù¶«Î÷Äã×î¶àÖ»ÄÜÓĞÒ»¼ş¡£\n");
                        }
        }

//      15 sec corpse loot protection. Only killer/self can loot the corpse.    
        
        if (env->query("allow_to_loot")) {
                if (env->query("death_time")+15 > time()) {
                        if ( member_array( me,env->query("allow_to_loot")) == -1
                                && env->query("victim_name")!= me->query("name"))
                                return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
                }
        }
        if (obj->query("allow_to_loot")) {
                if (obj->query("death_time")+15 > time()) {
                        if ( member_array( me,obj->query("allow_to_loot")) == -1
                                && obj->query("victim_name")!= me->query("name"))
                                return notify_fail("ÄãÏÖÔÚ»¹²»ÄÜÄÃÆğÕâ¼ş¶«Î÷¡£\n");
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
                return notify_fail("Äã²»ÄÜ±³¸º»îÎï¡£\n");
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
                        message_vision( "$N½«$n·öÁËÆğÀ´±³ÔÚ±³ÉÏ¡£\n", me, obj )
                else 
                        if(old_env==environment(me)) prep =  "¼ñÆğ"
                        else if(old_env->is_character()) prep =  "´Ó" + old_env->name() + "ÉíÉÏ" + (equipped? "³ıÏÂ" : "ËÑ³ö")
                        else switch( old_env->query("prep") ) 
                                case "on"
                                        prep = "´Ó" + old_env->name() + "ÉÏÄÃÆğ"
                                        break
                                case "under"
                                        prep = "´Ó" + old_env->name() + "ÏÂÄÃ³ö"
                                        break
                                case "behind"
                                        prep = "´Ó" + old_env->name() + "ºóÄÃ³ö"
                                        break
                                case "inside"
                                        prep = "´Ó" + old_env->name() + "ÖĞÄÃ³ö"
                                        break
                                default
                                        prep = "´Ó" + old_env->name() + "ÖĞÄÃ³ö"
                                        break
                        }
                        message_vision( sprintf("$N%sÒ»%s$n¡£\n", prep
                                obj->query("unit")), me, obj )
                
                return 1
        
        else return 0
int do_putitem(string arg
        object me = this_player(),dest=this_object()
        string target, item
        object obj, *inv, obj2
        int i, amount
        if(!arg) return notify_fail("ÄãÒª½«Ê²÷á [2;37;0m0mÍ³¡¿»ÆÉ½·ğ¹â(/d/huangshan/guangming.c)¾°¹ÛÏÖÔÚ¾ÍÒª·¢ÉúÁË£¬ÏÖÔÚhappenÊÇ1¡£

 [2;37;0mÉúÁË£¬ÏÖÔÚhappenÊÇ1¡£

 [2;37;0m£¿\n")
        if (present(target,environment(me)) != dest
                return 0
       
        if(sscanf(item, "%d %s", amount, item)==2) 
                if( !objectp(obj = present(item, me)) 
                        return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n")
                if( !obj->query_amount() 
                        return notify_fail( obj->name() + "²»ÄÜ±»·Ö¿ª¡£\n")
                if( amount < 1 
                        return notify_fail("¶«Î÷µÄÊıÁ¿ÖÁÉÙÊÇÒ»¸ö¡£\n")
                if( amount > obj->query_amount() 
                        return notify_fail("ÄãÃ»ÓĞÄÇ÷á¶àµÄ" + obj->name() + "¡£\n")
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
                return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n")
        return do_put(me, obj, dest)
int do_put(object me, object obj, object dest
        string prep
        int container_size
       
        if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore")
                return notify_fail("Äã²»¿ÉÒÔÕâÃ´×ö¡£\n")
        if (obj->is_container()
                return notify_fail("Äã²»ÄÜ°ÑÈİÆ÷·ÅÔÚÁíÒ»¸öÈİÆ÷Àï¡£\n");
        if( obj == dest
                        return notify_fail("Äã²»¿ÉÒÔÕâÃ´×ö¡£\n")
       
        if(dest->is_closed()
                return notify_fail("ÄãÒªÏÈ°Ñ" + dest->name() + "´ò¿ª¡£\n")
        container_size = dest->query("size") ? dest->query("size") : MAX_ITEM
        // ÕâÀïÓĞ±ğÓÚÆÕÍ¨putÖ¸Áî£¬Òò´Ë²»ÄÜreturn notify_fail¡£ annie 08.200
        // <-------------------------------------------------------------
        if(sizeof(all_inventory(dest)) >= container_size
        
                tell_object(me,dest->name() + "ÀïÃæ×î¶àÖ»ÄÜ·Å" + chinese_number(container_size) 
                                "¼şÎïÆ·¡£\n")
                return 1
        
        if (obj->query("no_stock")
        
                tell_object(me,"ÕâÑù¶«Î÷ÎŞ·¨´æ·Å¡£\n")
                return 1
        
        if (obj->query("value") < 4)    // ÎŞ·¨µäµ±µÄ¶«Î÷±»ÈÏÎªÊÇunique item¡
        
                tell_object(me,"ÕâÑù¶«Î÷²¢²»Öµ¶àÉÙÇ®£¬Ã»ÓĞĞ¡ĞÄ±£´æµÄ±ØÒª¡£\n")
                return 1
        
        // --------------------------------------------------------------
       
        switch((string)dest->query("prep")) 
                case "on" 
                        prep = "·ÅÔÚ" + dest->name() + "ÉÏ"
                        break
                case "under" 
                        prep = "·ÅÔÚ" + dest->name() + "ÏÂ"
                        break
                case "behind" 
                        prep = "·ÅÔÚ" + dest->name() + "ºóÃæ"
                        break
                case "insdie" 
                        prep = "·Å½ø" + dest->name() + "ÀïÃæ"
                        break
                default 
                        prep = "·Å½ø" + dest->name() + "ÀïÃæ"
                        break
        
        if( obj->move(dest) ) 
                message_vision( sprintf("$N½«Ò»%s%s%s¡£\n"
                        obj->query("unit"), obj->name(), prep)
                        me )
                if(obj->query("no_drop") || obj->query("no_get")|| obj->query("lore")
                        dest->add("no_give",1)
                reset_item_list(dest)
                return 1
        
        else return 0
/
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨X¨
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U¨t¨
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦¨t¨
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦¨t¨
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦©¦©
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨^¨k¨k¨k¨
¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 08.200
¡¡¡¡¡¡dancing_faery@hotmail.co
*
chat ÎÒĞŞ¸ÄÁË×Ô½¨Îİ×Ó
chat Ï£ÍûËü¿ÉÒÔ¹¤×÷..
chat ÕıÔÚuploda
chat ÕıÔÚupload

update /obj/item/box.c

chat lag .....................
chat* slogan

*/