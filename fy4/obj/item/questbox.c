// questbox.c By Silencer@fy2005 workgroup, Nov.2005
/*
	´ËÈİÆ÷×¨Îª´æ´¢£Ñ£Õ£å£ó£ôÎïÆ·£¬´æÈëÎïÆ·²»ÒÔÊµÌå´æÔÚ£¬Ö»ÄÜÓÃÓÚ£Ñ£õ£å£ó£ô½»»Ø
	´ËÈİÆ÷ÄÚÈİÒÔÎÄ¼ş´æÔÚÓÚÍæ¼ÒÄ¿Â¼ÖĞ£¬Îª½ÚÊ¡¶ÁĞ´¹ı³Ì£º
		¶Á£º½ö·¢ÉúÔÚ£ğ£ì£á£ù£å£ò´Ó£Î£Ğ£Ã´¦È¡³ö´ËÈİÆ÷Ê±£¬Í¬Ê±Ïú»Ù¸ÃÎÄ¼ş
		Ğ´£º½ö·¢ÉúÔÚ£ğ£ì£á£ù£å£òÖ÷¶¯´æÖüÈİÆ÷£¬»òÕßÍË³öÊ±£¬Ğ´ºó½«½«´ËÈİÆ÷ÊµÌåÏú»Ù
	ÔÚÈÎºÎÇé¿öÏÂ£¬ÎÄ¼şÓëÈİÆ÷Ö»ÄÜÓĞÒ»¼ş´æÔÚ¡£
	ÆäÄ¿µÄÔÚÓÚ£º
	£¨£±£©Ãâ³ı´ó²¿·ÖĞèÒªÔÚÏß±£´æ£ñ£õ£å£ó£ôÎïÆ·µÄĞèÒª	
	£¨£²£©½ÚÊ¡ÏµÍ³ÖĞ´óÁ¿ÎŞÎ½ÈİÆ÷ºÍ£ä£õ£í£í£ùµÄ×ÊÔ´
	Èç¹ûÖ»¿¼ÂÇµ½×ÔÉí£é£ä£¬Ã»ÓĞÈÎºÎĞèÒªÔÙ±£³Ö³¤ÆÚÔÚÏß¡£
	
	¿ÉÄÜºó¹û£º
	£¨£±£©¸ÃÈİÆ÷ÖĞµÄÎïÆ·Ö»½ø²»³ö£¬	¼õÉÙ£ñ£õ£å£ó£ôÎïÆ·ÔÚ²»Í¬Íæ¼Ò¼äµÄÁ÷Í¨£¬²»Ò»¶¨ÊÇ¼ş»µÊÂ
	£¨£²£©ÓÉÓÚËüÊ®·Ö±ãÀû¿É¿¿£¬¸ßµÈ¼¶µÄÍæ¼Ò¿ÉÌæµÍµÈ¼¶µÄÍæ¼Ò´óÁ¿´æÖü£ñ£õ£å£ó£ôÎïÆ·£¬			

*/
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

int do_qput(string arg);
int do_qqput(object me, object obj);
int do_qsave();
varargs int do_qqsave(object me);
int do_qdiscard(string arg); 
varargs int do_qqdiscard(string arg, object me, int silent);

string replace_color(string arg);

mapping items=([]);
/* ¸ñÊ½Îª£º
items = ([
	Ìú½££º	5
	ÉáÀû×Ó£º 1
]);	
*/

void create() {
	set_name("ĞşÁéÓñºĞ", ({ "treasure box","treasurebox",}) );
	set("long","
Ò»¸öÉÁË¸×Åµ­µ­ÓñÉ«µÄºĞ×Ó£¬¶¥¶ËÁú·É·ïÎèµØĞ´×ÅËÄ¸ö´ó×Ö
¡º·çÔÆÒÀ¾É¡»¡£ÕâÊÇ·çÔÆÖĞ×¨ÃÅÓÃÀ´´æÖüÌì»úÀÏÈËÈÎÎñÎïÆ·
µÄ±¦ºĞ¡££¨¾ßÌåÊ¹ÓÃ·½·¨Çë²Î¿´£è£å£ì£ğ¡¡£ç£á£í£åÖĞµÄÌì
»úÈÎÎñÆª£©·ÅÈë´ËÏäÖĞµÄÎïÆ·½«Ö»ÄÜÓÃÓÚ£Ñ£õ£å£ó£ô£¬¶ø
²»ÔÙÄÜÈ¡³ö¡£

´ËÓñºĞÖ§³ÖÒÔÏÂÖ¸Áî£º
£¨£±£©qlook ²ì¿´ĞşÁéÓñºĞÎïÆ·ÁĞ±í
£¨£²£©qput <Ä³ÎïÓ¢ÎÄ£é£ä> °ÑÎïÆ··ÅÈëĞşÁéÓñºĞ
£¨£³£©qdiscard <Ä³ÎïÖĞÎÄÃû×Ö> °ÑÓñºĞÖĞÄ³ÎïÓÀ¾Ã¶ªÆú
£¨£´£©qdiscard num <Ä³ÎïÖĞÎÄÃû×Ö> °ÑÓñºĞÖĞ£î£õ£íÊıÁ¿µÄÄ³ÎïÓÀ¾Ã¶ªÆú
£¨£µ£©qdiscard all Çå³ıËùÓĞÓñºĞÖĞµÄÎïÆ·
£¨£¶£©qsave¡¡°ÑÓñºĞ½»»¹¸øÏµÍ³´æ´¢ÆğÀ´

ÔÚÌì»úÀÏÈË´¦¿ÉÊ¹ÓÃ
£¨£·£©qreturn ×Ô¶¯ËÑÑ°ÓñºĞ½»»¹×ÔÉíÈÎÎñ
£¨£¸£©qreturn <Ä³ÎïÖĞÎÄÃû> Ö¸¶¨½»»¹Ä³Ìì»úÈÎÎñÎïÆ·

\n");
	set("unit", "¸ö");
	set("lore", 1);
	set("quest_box",1);
	set("no_split",1);
	set("no_drop", 1);
}


void init() {
	object ob;

	if(this_player() && environment()==this_player() ) {
		set("owner_id",this_player()->query("id"));
		set_name( this_player()->name(1) + "µÄĞşÁéÓñºĞ", ({ "treasure box","treasurebox" }) );
		add_action("do_qput", "qput");
		add_action("do_qlook", "qlook");
		add_action("do_qdiscard", "qdiscard");
		add_action("do_qsave", "qsave");
	}
}

mapping item_list(){
	return items;
}

string query_save_file() {
	string id;
	if(!stringp(id = query("owner_id"))) return 0;
	return sprintf(DATA_DIR "user/%c/%s/treasurebox", id[0],id);
}

int do_qput(string arg) {
	
	object *inv, me, obj, obj2;
	int amount;
	string item;
	
	if (!arg)
		return notify_fail("ÄãÒªÍùĞşÁéÓñºĞÀï·ÅÊ²Ã´¶«Î÷£¿\n");
		
	me = this_player();
	inv = all_inventory(me);
	
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
		if( obj->query("no_drop"))	// Enough? Qput == Burn I guess
			return notify_fail("ÕâÑù¶«Î÷²»ÄÜ·ÅÈëĞşÁéÓñºĞÀï¡£\n");
		if (obj->query("dynamic_quest"))
			return notify_fail("TASK·Å½øÈ¥ÄãÔõÃ´»¹°¡£¿\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "²»ÄÜ±»·Ö¿ª·Å¡£\n");
		if( amount < 1 )
			return notify_fail("¶«Î÷µÄÊıÁ¿ÖÁÉÙÊÇÒ»¸ö¡£\n");
		if( amount > obj->query_amount() )
			return notify_fail("ÄãÃ»ÓĞÄÇ÷á¶àµÄ" + obj->name() + "¡£\n");
		else if( amount == (int)obj->query_amount() )
			return do_qqput(me, obj);
		else {
			obj->set_amount( (int)obj->query_amount() - amount );
			seteuid(getuid());
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));
			if(!do_qqput(me, obj2)) {
				obj->set_amount( (int)obj->query_amount() + amount );
				return 0;
			}
			if (obj2) destruct(obj2);
			return 1;
		}
	} else {
		if(!objectp(obj = present(arg, me)))
			return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
		return do_qqput(me, obj);
	}
	
}


int do_qqput(object me, object obj)
{
	string prep,*dir, name;
	int container_size, amount,index;
	
    if(obj->query("no_drop") || obj->query("no_get")||obj->query("lore"))
    	return notify_fail("Äã²»ÄÜ½«´ËÎï·Åµ½ĞşÁéÓñºĞÖĞ¡£\n");
	
	if (obj->query("dynamic_quest"))
		return notify_fail("TASK·Å½øÈ¥Äã»¹ÔõÃ´»¹°¡£¿\n");
			
	if (obj == this_object())
		return notify_fail("·Åµ½×Ô¼ºÀïÃæ£¿¿ÖÅÂ²»ĞĞ¡£\n");
	
	dir = keys(items);
	name = obj->query("name");	// We use Chinese Name to index Items.
	index = member_array(name, dir);
		
	container_size = 50;
	
	//¡¡ÔÊĞí·ÅÈëÒÑÓĞµÄ¶«Î÷£¬¼´Ê¹ÒÑÂú
	if ( index == -1 && sizeof(items)>= container_size)	
		return notify_fail( "ĞşÁéÓñºĞÀïÃæ×î¶àÖ»ÄÜ·Å" + chinese_number(container_size)+"ÀàÎïÆ·¡£\n");
	
	prep = "·Å½øĞşÁéÓñºĞÀïÃæ";

	message_vision( sprintf("$N½«Ò»%s%s%s¡£\n",
			obj->query("unit"), obj->name(), prep),
			me );
	amount = obj->query_amount()>0? obj->query_amount(): 1;
			
	if (index != -1) {
		items[dir[index]] += amount;
	} else
		items[name]= amount;
	
	destruct(obj);
	return 1;
}

int do_qlook(){
	int i,j,k,extra,num;
	string *list,outstring;

	if (this_object()->query("timer/op") + 4 > time()) {
		write("Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ĞşÁéÓñºĞÃüÁî²»ÄÜÁ¬Ğø²Ù×÷£¬ÇëµÈ´ı£´ÃëÖÓ¡£\n");
		return 1;
	}		
	this_object()->set("timer/op", time());
			
	num = sizeof(items);
	
	write(WHT"\t  " + name()+ "ÖĞµÄÎïÆ·Çåµ¥£¨"+num+"/50£©\n"NOR);
    write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);

    if (!num)	write (HIR "¡¡¡¡¿Õ¿ÕÈçÒ²£¬´ó¶ÇÄÜÈİÌìÏÂÍòÎï¡£\n"NOR);
    else
    {
		list = keys(items);
		for(i=0; i<num; i++){
			k = 0;
			extra = 0;
			for(j=0; j<strlen(list[i]); j++) {
				if(list[i][j] == ESC[0]) {
					k = 1;	
				}
				if(k == 1) {
					extra++;
				}
				if(list[i][j] == 'm') {
					k = 0;	
				}
			}					      			
        	if (i%2==0){
        		outstring = sprintf("%-*s %5d©¦", 
        					22+extra,
        					list[i],
        					items[list[i]]);
        		if (i==num-1)
        			outstring +="\n";
        	}			
        	else
        		outstring = sprintf("%-*s %5d\n", 
        					22+extra,
        					list[i],
        					items[list[i]]);
        	write(outstring);
        }
    }
    write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
    
	return 1;
}

int do_qsave(){
	object me;
	me = this_player();	
	do_qqsave(me);
	return 1;
}

varargs int do_qqsave(object me){
	
	int num;
	save();
	tell_object(me,"ĞşÁéÓñºĞÓÉÏµÍ³×Ô¶¯±£´æ£¬ĞèÒªÊ±ÇëÖÁğĞğÄ¸óÉÏ¹ÙÑ©¶ù´¦È¡³ö¡£\n");
	num = sizeof(items);
	log_file( "QBOX_LOG", sprintf("(%s) %s ´æ´¢³É¹¦£¨%d£©¡£\n", 
			ctime(time()),
			me->query("id"),
			num)
			); 
	destruct(this_object());
	return 1;
}

// DON"T CALL THIS FUCTION FROM OUTSIDE
// it can't garantee item will be deleted.
int do_qdiscard(string arg) {
	object me;
	me = this_player();
	
	if (this_object()->query("timer/op") + 2> time()) {
		write("Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ĞşÁéÓñºĞÃüÁî²»ÄÜÁ¬Ğø²Ù×÷£¬ÇëµÈ´ı£²ÃëÖÓ¡£\n");
		return 1;
	}
	this_object()->set("timer/op", time());
	
	do_qqdiscard(arg, me, 0);	
	return 1;
}

// when call this from outside, make sure the item exists yourself!
varargs int do_qqdiscard(string arg, object me, int silent) {
	int num, amount, amount1, index, i;
	string item,*dir;
	
	if(!arg){
		tell_object(me,"ÄãÒª¶ªÆúÄÄÒ»¼şÎïÆ·£¿\n");
		return 0;
	}
	
	if (arg == "all") {
		items = ([]);
		tell_object(me,"ĞşÁéÓñºĞÇåÀíÍê±Ï¡£¡£¡£¡£ËùÓĞÎïÆ·±»É¾³ı¡£\n");
		return 1;
	}
			
	if(sscanf(arg, "%d %s", amount1, item)==2)
		arg = item;
	else
		amount1 = 1;
	
	if (amount1<=0){
		tell_object(me,"ÏëÒª¶ªÆúµÄ¶«Î÷ÊıÄ¿±ØĞëÊÇÕıÊı¡£\n");
		return 1;
	}
			
	arg = replace_color(arg);
	num = sizeof(items);
	dir = keys(items);
	index = member_array(arg, dir);
	if (index == -1) {		// ×öÒ»´ÎÎŞÑÕÉ«µÄÆ¥Åä
		for (i= 0; i<num; i++) {
			if ( arg == "/feature/nada"->ngstr(dir[i])) {
				index = i;
				break;
			}
		}
	}
	
	if (index == -1) {
		tell_object(me,"ĞşÁéÓñºĞÖĞÃ»ÓĞÄãËùÒªÏú»ÙµÄÎï¼ş¡£\n");
		return 0;
	}
	
	amount = items[dir[index]];
	// if amount1 is bigger.. assume ppl wants to delete all
	if (amount > amount1)	{
		items[dir[index]]= amount-amount1;
			tell_object(me,"ĞşÁéÓñºĞÖĞµÄ"+arg + "¼õÉÙÁË"+chinese_number(amount1)+"¸öµ¥Î»¡£\n");
	}
	else
	{ 
		num --;
		if (sizeof(items) == 1){
			items = ([]);
			if (!silent) 	
				tell_object(me,"ÄãµÄĞşÁéÓñºĞ¿ÕÁË¡£\n");
		} else 
			map_delete(items, dir[index]);
			if (!silent)	
				tell_object(me,"ĞşÁéÓñºĞÖĞËùÓĞµÄ"+arg+"¶¼±»Çå¿ÕÁË¡£\n");
	}
	return 1;
}

string replace_color(string ccolor){
		ccolor = replace_string(ccolor, "$BLK$", "[0;30m");
        ccolor = replace_string(ccolor, "$RED$", "[0;31m");
        ccolor = replace_string(ccolor, "$GRN$", "[0;32m");
        ccolor = replace_string(ccolor, "$YEL$", "[0;33m");
        ccolor = replace_string(ccolor, "$BLU$", "[0;34m");
        ccolor = replace_string(ccolor, "$MAG$", "[0;35m");
        ccolor = replace_string(ccolor, "$CYN$", "[0;36m");
        ccolor = replace_string(ccolor, "$WHT$", "[0;37m");
        ccolor = replace_string(ccolor, "$HIR$", "[1;31m");
        ccolor = replace_string(ccolor, "$HIG$", "[1;32m");
        ccolor = replace_string(ccolor, "$HIY$", "[1;33m");
        ccolor = replace_string(ccolor, "$HIB$", "[1;34m");
        ccolor = replace_string(ccolor, "$HIM$", "[1;35m");
        ccolor = replace_string(ccolor, "$HIC$", "[1;36m");
        ccolor = replace_string(ccolor, "$HIW$", "[1;37m");
        ccolor = replace_string(ccolor, "$NOR$", "[2;37;0m");
    return ccolor;
}    
