// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int gift_points;
	int used_gift_points;
	if( !arg ) return notify_fail("дЦр╙╥жеД╣╫дд╦Ж╡нйЩиоё©\n");
	gift_points = me->query("gift_points");
	used_gift_points = me->query("used_gift_points");
	if( used_gift_points >= gift_points )
	return notify_fail("дЦц╩сп╡нйЩ╣Ц║ё\n");
	if(me->is_busy())
	return notify_fail("дЦио╦Ж╤╞вВ╩╧ц╩мЙЁи║ё\n");
	switch (arg) {
	case "╡ежг" :
	case "caizhi" :
			if((int) me->query("int") >=20)
			return notify_fail("дЦ╣д╡ежгря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
			me->add("used_gift_points",1);
			me->add("int",1);
			break;
        case "лЕжй" :
        case "tizhi" :
                        if((int) me->query("con") >=20)
                        return notify_fail("дЦ╣длЕжйря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("con",1);
                        break;
        case "аИпт" :
        case "lingxing" :
                        if((int) me->query("spi") >=20)
                        return notify_fail("дЦ╣даИптря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("spi",1);
                        break;
        case "Вха╕" :
        case "meili" :
                        if((int) me->query("per") >=20)
                        return notify_fail("дЦ╣дВха╕ря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("per",1);
                        break;
        case "сбфЬ" :
        case "yongqi" :
                        if((int) me->query("cor") >=20)
                        return notify_fail("дЦ╣дсбфЬря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("cor",1);
                        break;
        case "а╕а©" :
        case "liliang" :
                        if((int) me->query("str") >=20)
                        return notify_fail("дЦ╣да╕а©ря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("str",1);
                        break;
        case "дма╕" :
        case "naili" :
                        if((int) me->query("dur") >=20)
                        return notify_fail("дЦ╣ддма╕ря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("dur",1);
                        break;
        case "хмпт" :
        case "renxing" :
                        if((int) me->query("fle") >=20)
                        return notify_fail("дЦ╣дхмптря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("fle",1);
                        break;
        case "кы╤х" :
        case "sudu" :
                        if((int) me->query("agi") >=20)
                        return notify_fail("дЦ╣дкы╤хря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("agi",1);
                        break;
        case "фЬа©" :
        case "qiliang" :
                        if((int) me->query("tol") >=20)
                        return notify_fail("дЦ╣дфЬа©ря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("tol",1);
                        break;
        case "ткфЬ" :
        case "yunqi" :
                        if((int) me->query("kar") >=20)
                        return notify_fail("дЦ╣дткфЬря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("kar",1);
                        break;
        case "╤╗а╕" :
        case "dingli" :
                        if((int) me->query("cps") >=20)
                        return notify_fail("дЦ╣д╤╗а╕ря╢О╣╫акиоочё╛╡╩©иртсц╥жеД╣д╥╫╥╗тылА╦ъак║ё\n");
                        me->add("used_gift_points",1);
                        me->add("cps",1);
                        break;
        default :
			return notify_fail("ц╩спуБ╦Ж╡нйЩ║ё\n");

	}
	write("Ok.\n");
	me->start_busy(1);
	return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37m╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓[0m
[0;1;36mж╦аН╦Яй╫ : 	distribute <йТпт╣Ц>[0m
[0;1;37m╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓[0m   

уБ╦Жж╦аН©иртхцдЦ╫╚йТпт╣Ц╥жеД╣╫дЦж╦╤╗╣д╡нйЩио║ёйТпт╣Ц
р╩╣╘╥жеД╣Тё╛╫╚сют╤╡╩©и╦Э╦д║ё

distribute ╡ежг хцдЦ╫╚р╩╣ЦйТпт╥жеД╣╫╡ежгио║ё

хГ╡╩©ийДхКжпндё╛©исцф╢рТ╢ЗлФ║ё
╡ежг caizhi	лЕжй tizhi
аИпт lingxing	Вха╕ meili
сбфЬ yongqi	а╕а© liliang
дма╕ naili	хмпт renxing
кы╤х sudu	фЬа© qiliang
ткфЬ yunqi	╤╗а╕ dingli

сп╧ь╡нйЩ╣Цё╛йТптё╗╡ежгё╛а╕а©╣хё╘ё╨╡н╪Ш Help attributes.txt

[0;1;37m╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓╘╓[0m   
HELP
        );
        return 1;
}
