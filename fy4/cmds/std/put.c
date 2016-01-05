// put.c

#define MAX_ITEM 25

inherit F_CLEAN_UP;


int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("ÄãÒª½«Ê²÷á¶«Î÷·Å½øÄÄÀï£¿\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("ÄãÒª¸øË­Ê²÷á¶«Î÷£¿\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("ÕâÀïÃ»ÓĞÕâÑù¶«Î÷¡£\n");

	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "²»ÄÜ±»·Ö¿ª¡£\n");
		if( amount < 1 )
			return notify_fail("¶«Î÷µÄÊıÁ¿ÖÁÉÙÊÇÒ»¸ö¡£\n");
		if( amount > obj->query_amount() )
			return notify_fail("ÄãÃ»ÓĞÄÇ÷á¶àµÄ" + obj->name() + "¡£\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
							obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));

				if (do_put(me, obj2, dest))
				{
					obj->set_amount( (int)obj->query_amount() - amount );
					return 1;
				}		
				if (obj2) destruct(obj2);
				return 0;
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest  && !inv[i]->query("no_drop")) 
			do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
	return do_put(me, obj, dest);
}


int do_put(object me, object obj, object dest)
{
	string prep;
	int container_size;
	
    if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
            return notify_fail("Äã²»¿ÉÒÔÕâÃ´×ö¡£\n");
	
	if (!dest->is_container())
			return notify_fail(dest->name()+"²»ÊÇÈİÆ÷¡£\n");
		
	if (obj->is_container())
		return notify_fail("Äã²»ÄÜ°ÑÈİÆ÷·ÅÔÚÁíÒ»¸öÈİÆ÷Àï¡£\n");	

	if( obj == dest)
			return notify_fail("Äã²»¿ÉÒÔÕâÃ´×ö¡£\n");
	
	if(dest->is_closed())
		return notify_fail("ÄãÒªÏÈ°Ñ" + dest->name() + "´ò¿ª¡£\n");

	container_size = dest->query("size") ? dest->query("size") : MAX_ITEM;
	
	if(sizeof(all_inventory(dest)) >= container_size)
		return notify_fail( dest->name() + "ÀïÃæ×î¶àÖ»ÄÜ·Å" + chinese_number(container_size) +
				"¼şÎïÆ·¡£\n");
	
	switch((string)dest->query("prep")) {
		case "on" :
			prep = "·ÅÔÚ" + dest->name() + "ÉÏ";
			break;
		case "under" :
			prep = "·ÅÔÚ" + dest->name() + "ÏÂ";
			break;
		case "behind" :
			prep = "·ÅÔÚ" + dest->name() + "ºóÃæ";
			break;
		case "insdie" :
			prep = "·Å½ø" + dest->name() + "ÀïÃæ";
			break;
		default :
			prep = "·Å½ø" + dest->name() + "ÀïÃæ";
			break;
	}
	if( obj->move(dest) ) {
		message_vision( sprintf("$N½«Ò»%s%s%s¡£\n",
			obj->query("unit"), obj->name(), prep),
			me );
		if(obj->query("no_drop") || obj->query("no_get")|| obj->query("lore"))
			dest->add("no_give",1);
		return 1;
	}
	else return 0;
}




int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	put <ÎïÆ·Ãû³Æ> in <Ä³ÈİÆ÷>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
Õâ¸öÖ¸Áî¿ÉÒÔÈÃÄã½«Ä³ÑùÎïÆ··Å½øÒ»¸öÈİÆ÷¡£

Ïà¹ØÖ¸Áî£ºget	drop
 
HELP
    );
    return 1;
}
