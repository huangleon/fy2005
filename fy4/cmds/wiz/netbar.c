// netbar.c

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	string site;

	if (!arg)
		NETBAR_D->print();
	else if (arg == "-s") {
		NETBAR_D->netbar_switch();	
	}	
	else if (sscanf(arg, "-y + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("²»ÄÜÊ¹ÓÃÒÔ *, +, ? ½áÎ²µÄµØÖ·¡£\n");
		else
			NETBAR_D->add(site);
	}
	else if (sscanf(arg, "-y - %s", site) == 1) {
		NETBAR_D->delete(site);
	}
	else if (sscanf(arg, "-n + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("²»ÄÜÊ¹ÓÃÒÔ *, +, ? ½áÎ²µÄµØÖ·¡£\n");
		else
			NETBAR_D->add_ban(site);
	}
	else if (sscanf(arg, "-n - %s", site) == 1) {
		NETBAR_D->delete_ban(site);
	}
	else if (sscanf(arg, "-a + %s", site) == 1) {
		if (site[sizeof(site)-1] == '*' ||
		    site[sizeof(site)-1] == '?' ||
		    site[sizeof(site)-1] == '+')
			write("²»ÄÜÊ¹ÓÃÒÔ *, +, ? ½áÎ²µÄµØÖ·¡£\n");
		else
			NETBAR_D->add_all(site);
	}
	else if (sscanf(arg, "-a - %s", site) == 1) {
		NETBAR_D->delete_all(site);
	}	
		
	else 
		write("Çë²Î¿´Ö¸Áî¸ñÊ½	netbar -²ÎÊı [+|- site]\n");

	return 1;
	
}

int help()
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ :		netbar -²ÎÊı [+|- site] [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

·çÔÆ2005È±Ê¡ÉèÖÃÎªÃ¿¸öipµÇÂ½Èı¸öÕËºÅ¡£
ÕâÌõÃüÁîÊÇÓÃÀ´¾ßÌåµ÷½ÚÃ¿¸öipµÄµÇÂ½ÈËÊı

Ê¹ÓÃËµÃ÷

netbar		Êä³öÁĞ±í

netbar -s	¿ª¹Ø²ÎÊı£¬ÓÃÀ´¿ØÖÆÊÇ·ñÏŞÖÆipµÄµÇÂ½ÈËÊı

netbar -y	+ xx.xx.xx.xx
netbar -y	- xx.xx.xx.xx
			½«Ä³¸öip»òip¶Î¼ÓÈë/Ïû³ınetbar£¬¸Ãip¿ÉÒÔÓĞ¼Ó±¶µÄµÇÂ½Ïß

netbar -n	+ xx.xx.xx.xx
netbar -n	- xx.xx.xx.xx
			½«Ä³¸öip»òip¶Î¼ÓÈë/Ïû³ınetbarn£¬¸Ãip½«Ã»ÓĞ¼Ó±¶µÄµÇÂ½Ïß

ÎªÊ²Ã´ÓĞnetbarºÍnetbarnÁ½ÖÖÄØ£¬netbarnÊÇÓÃÀ´´¦ÀíÒ»ÖÖº±¼ûµÄ
Çé¿ö£¬±ÈÈçËµ£¬ÄãÏëÈÃ128.22.22.*ÓĞ¼Ó±¶µÄµÇÂ½£¬µ«ÓÖ²»ÏëÈÃ
128.22.22.3ÓĞ¼Ó±¶µÄµÇÂ½£¬ÄÇÃ´¾ÍÓ¦¸ÃÍ¬Ê±Ê¹ÓÃÁ½¸öÃüÁî
netbar -n + 128.22.22.3
netbar -y + 128.22.22


netbar -a + xx.xx.xx.xx		¸ÃipÎŞµÇÂ½ÈËÊıÏŞÖÆ
netbar -a - xx.xx.xx.xx		»Ö¸´µ½Õı³£×´Ì¬
×¢Òâ£¬´ËÃüÁî±ØĞëÊÇÍêÕûµÄip²ÅÓĞĞ§¡£


ÓĞ¹ØÃüÁî£ºloginlock ¿É¸Ä±äÃ¿¸öipµÄµÇÂ½ÈËÊı

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
	);
	return 1;
}