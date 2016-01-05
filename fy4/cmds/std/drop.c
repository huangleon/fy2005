// drop.c

inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj, *inv, obj2;
	int i, amount;
	string item;
	mixed no_drop;

	if(!arg) return notify_fail("─у╥к╢к╞·╩▓ўс╢л╬ўг┐\n");

	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("─у╔э╔╧├╗╙╨╒т╤∙╢л╬ўбг\n");
		if( stringp(obj->query("no_drop")) )
			return notify_fail( (string)obj->query("no_drop") );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "▓╗─▄▒╗╖╓┐к╢к╞·бг\n");
		if( amount < 1 )
			return notify_fail("╢л╬ў╡─╩¤┴┐╓┴╔┘╩╟╥╗╕Ўбг\n");
		
		if( no_drop = obj->query("no_drop") )
			return notify_fail( stringp(no_drop) ? no_drop : "╒т╤∙╢л╬ў▓╗─▄╦ц╥т╢к╞·бг\n");
				
		if( amount > obj->query_amount() )
			return notify_fail("─у├╗╙╨─╟ўс╢р╡─" + obj->name() + "бг\n");
		else if( amount == (int)obj->query_amount() )
			return do_drop(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			return do_drop(me, obj2);
		}
	}

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			do_drop(me, inv[i]);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(arg, me)))
		return notify_fail("─у╔э╔╧├╗╙╨╒т╤∙╢л╬ўбг\n");
	return do_drop(me, obj);
}

int do_drop(object me, object obj)
{
	mixed no_drop;

	if( no_drop = obj->query("no_drop") )
		return notify_fail( stringp(no_drop) ? no_drop : "╒т╤∙╢л╬ў▓╗─▄╦ц╥т╢к╞·бг\n");

	if (obj->move(environment(me))) {
		if( obj->is_character() )
			message_vision("$N╜л$n┤╙▒│╔╧╖┼┴╦╧┬└┤гм╠╔╘┌╡╪╔╧бг\n", me, obj);
		else {
			message_vision( sprintf("$N╢к╧┬╥╗%s$nбг\n",	obj->query("unit")),
				me, obj );
			me->save();
			if( (int) obj->query("value") < 4 && !obj->value() 
				&& !obj->query("dynamic_quest") ) {
				write("╥Є╬к╒т╤∙╢л╬ў▓в▓╗╓╡╟огм╦∙╥╘╚╦├╟▓в▓╗╗с╫в╥т╡╜╦№╡─┤ц╘┌бг\n");
				destruct(obj);
			}
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	drop <╬я╞╖├√│╞>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
╒т╕Ў╓╕┴ю┐╔╥╘╚├─у╢к╧┬─у╦∙╨п┤°╡─╬я╞╖бг

╧р╣╪╓╕┴юг║get

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
HELP
    );
    return 1;
}
 
