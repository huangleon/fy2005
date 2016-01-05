// Room: /u/mon/poem/clubpoem by mon@xyj 7/25/97
//		--- Modified from one xyj version by silencer@fy4.
// Ã÷ÔÂ¶Ô´Ê°æ^o^ annie 1.1.2005

inherit ROOM;
#include <ansi.h>;
int POEMS=2;
string author,title,*poem;
string author1,title1,*poem1;
string current,last;
string curr_show;
int length,length1,running;
int index,chance;
int poem_index,answerd,ans_curr,ans_last;
void new_poem();
void copy_to_old();
void do_test();
void do_init(object me);
void poem_reward(object me,string arg);
void poem_reward1(object me);
void poem_penalty(object me);
int find_newline();
string mixup(string str);
string enscript(string arg);

void create ()
{
    set ("short", "ÇàÔÆÂ¥");
    set ("long", @LONG
µÇÉÏÇàÔÆÊ«Éç¶þÂ¥£¬·çÔÆ³ÇµÄ·±»ª¾°Ïó¾¡ÊÕÑÛµ×£¬¶«´°ÍâÊÇÌìÌ³£¬²»Ê±ÓÐ½ø¹¬
µÄ³µÂíÐÐ¹ý¡£ÕâÀïÓÀÔ¶ÊÇÈÈÈÈÄÖÄÖµÄ£¬½õÒÂµÄ¹«×Ó¸çÃÇ¶ù£¬²¼ÒÂµÄËáÐã²ÅÃÇ£¬¶¼Ï²
»¶¾ÛÔÚÕâÀïÆ·²èÒ÷Ê«£¬Ì¸¹ÅÂÛ½ñ£¬¾ÍÁ¬¶Ë²èËÍ²ËµÄÐ¡¶þ¸çÒ²ÄÜ³ö¿Ú³ÉÕÂ¡£×î½üÕâ¶ù
À´ÁË¸öÐã²Å£¬×îÏ²»¶ÓëÈË¶ÔÊ«£¬»¹ÔÚ¹ñÌ¨ÉÏÐÂÌùÁËÕÅ[33mÆôÊÂ[32m¡£
LONG);
    set("exits",  ([  /*  sizeof()  ==  1  */
	"down"  :  __DIR__"shishe",
      ]));
    set("objects", ([
	__DIR__"npc/suanxiucai": 1,
      ]));
    set("coor/x",-20);
    set("coor/y",60);
    set("coor/z",10);
    set("map","fynorth");
    set("file","/data/poem/poem3");
    setup();
    remove_call_out("do_test");
    remove_call_out("do_test1");
    poem_index=-1;
    running=0;
}

void do_test1()
{
	tell_room(this_object(), CYN"ËáÐã²ÅÒ¡Í·»ÎÄÔÒ÷µÀ£ºÊÅË®Öð²ÐÔÂ£¬Ê±É°ÎÞÓë¶à¡£\n"NOR);
	call_out("do_test",10);
}

void init()
{   
    add_action("do_answer","answer");
    add_action("do_look","look");    
    //    	call_out("do_init",1,this_player());
    if(running==0) {
	running=1;
	new_poem();
	copy_to_old();
	new_poem();
	do_test();
//	call_out("do_test",2);
    }
}
/*
void do_init(object me)
{ 
	return;
}*/
int do_answer(string arg)
{ 
    object me=this_player(),ob;
    if(!arg) return notify_fail("ÄãÏë»Ø´ðÊ²Ã´£¿\n");
    if(me->is_busy())
	return notify_fail("Äã»¹ÊÇÏÈ°ÑÊÖÍ·µÄÊÂ¶ùÃ¦Íê°É¡£\n");
    if(me->query_temp("poemok")>50 && me->query("timer/last_poem")+ 300 > time() )
	return notify_fail("ËáÐã²ÅËµ£º¸óÏÂ±¥¶Á¾­Êé£¬Ñ§¸»Îå³µ£¬ÇëÐÝÏ¢Æ¬¿Ì£¬ÎÒÔÙÏë¼¸¸öÄÑµÄ£¡!\n");

//	me->set("timer/annie_poem_failed",time());
	if (me->query("timer/annie_poem_failed")+ 300 > time())
	{
		poem_penalty(me);
		return 1;
	}
    /*   	if( me->query("gin")<me->query("max_gin")/20 
		   || me->query("eff_gin")<me->query("max_gin")/20 )
		   return notify_fail("ÄãµÄ¾«²»¹»ÁË¡£\n");
	   if(living(me) ) 
		   me->receive_damage("gin",5+random(15),"¶ÁÊé¹ý¶ÈÐÄÁ¦½»´á±©×ä¡£");*/
    if(objectp(ob=present("suan xiucai",this_object()))
      && living(ob)) {
	switch(random(2)) {
	case 0: message_vision("$NËµµÀ£ºÊÇ£®£®£®"+arg+"£¿\n",me);
	    break;
	case 1: message_vision("$N´ðµÀ£º"+arg+"£¿\n",me);
	    break;
	}
	// check cheat here..grin
	if (strlen(arg) < strlen(current) -2 || strlen(arg) > strlen(current) +2 )
	{
	    me->add_temp("poem/wrong",10);
			if(me->query_temp("poem/wrong")>20) 
				poem_penalty(me);
		if (environment(me) != this_object())
			return 1;
	}





	if(arg==current && strlen(current)>2) {
	    if(ans_curr==1) {
		write("±ðÈËÒÑ¾­»Ø´ð¹ýÕâ¾äÊ«ÁË¡£\n");
		return 1;
	    }

	    ans_curr=1;
	    //change to a new poem once this one is answered.
	    index=length-1;
	    me->set_temp("poem/index",poem_index);

	current=replace_string(current," ","");
	current=replace_string(current,",","");
	current=replace_string(current,"£¬","");
	current=replace_string(current,"¡£","");
	current=replace_string(current,"£¡","");
	current=replace_string(current,"£¿","");

	    poem_reward(me,current);
	} else if(arg== last && strlen(last)>2) {
	    if(ans_last == 1) {
		write("±ðÈËÒÑ¾­»Ø´ð¹ýÕâ¾äÊ«ÁË¡£\n");
		return 1;
	    }
	    ans_last=1;

	last=replace_string(last," ","");
	last=replace_string(last,",","");
	last=replace_string(last,"£¬","");
	last=replace_string(last,"¡£","");
	last=replace_string(last,"£¡","");
	last=replace_string(last,"£¿","");

	    poem_reward(me,last);
	} else {
	    message_vision("ËáÐã²ÅÒ¡ÁËÒ¡Í·£ººÃÏó²»¶Ô°É£¿\n",me);
		if (!random(3))
		    me->add_temp("poem/wrong",1);
		if(me->query_temp("poem/wrong")>20) 
			poem_penalty(me);
	}
    } else {
	write("ËáÐã²Å²»ÔÚ£¬Ã»ÓÐÈË²ÃÅÐ¶Ô´íÁË£®£®£® £º£¨\n");
    }
    return 1;
}
void poem_penalty(object me)
{
	object r;
    message_vision(HIW"ËáÐã²ÅÒ¡Í·µÀ£ºÖªÖ®ÎªÖªÖ®£¬²»ÖªÎª²»Öª£¬·½ÊÇÖªÒ²¡£\n",me);
    message_vision(HIR"ËáÐã²ÅµÀ£ºÈ¥£¬È¥£¬È¥¡£\n",me);
    message_vision(MAG"ËáÐã²Å»Ó»ÓÐä×Ó£¬$NÌÚÔÆ¼ÝÎí°ãµØ´ÓÇàÔÆÂ¥ÉÏ·ÉÁË³öÈ¥¡£\n"NOR,me);
    me->set_temp("poem/wrong",0);
	r=find_object("/d/fy/jssju2");
	if (!r)
		r=load_object("/d/fy/jssju2");
	me->move(r);
    message_vision(HIG"Ö»ÌýµÃ»©À²Ò»Éù£¬Ò»¸öÈËÓ°×²¿ªÁË¶¥Â¥µÄÖ½´°£¬ÖØÖØµØÔÒÔÚÇ½ÉÏ¡£\n"NOR,me);
	me->unconcious();
	me->set("timer/annie_poem_failed",time());
    return;
}
void poem_reward(object me,string arg)
{
    me->set_temp("poem/wrong",0);
    message_vision(CYN"ËáÐã²ÅµãÍ·µÀ£º´ð¶ÔÁË£¬²»´í£¡²»´í£¡\n"NOR,me);
    me->add_temp("poemok",1);
    poem_reward1(me);
}
void poem_reward1(object me)
{  
    int dx,pot,lite;
    
    if (!me->query_skill("literate",1))
    	me->set_skill("literate",1);
    
    // 1 answer = 1 level, only need 11 answer to full ( read huangshan stone first)	
    lite = me->query_skill("literate",1)*8000;
    
    if (me->query_skill("literate",1) <= 60) {
	me->improve_skill("literate",lite);
	//	     		me->add("jing",-me->query("eff_jing")/20);
	//             		me->add("eff_jing",-me->query("max_jing")/20);
	write("ÄãµÄ¶ÁÊéÊ¶×Ö½ø²½ÁË£¡\n");
    }
    me->add("poem_answered",1);
    if (QUESTS_D->verify_quest(me,"¶ÔÊ«") && me->query_temp("poemok")>=3) {
	me->delete_temp("poemok");
	QUESTS_D->special_reward(me,"¶ÔÊ«");
    }    	
    //    	dx=me->query("poem_answered");
}
void do_test()
{  
    int newt;
    object ob;
//    string first,second,quest;
	string* poemstr,quest,first,second;
	int ann1,ann2,ann3;
    if(objectp(ob=present("suan xiucai",this_object()))
      && living(ob)) {
	if(strlen(current)>2 && ans_curr==0) {
	    last=current;
//	    last_all=current_all;
	    ans_last=0;
	}
	newt=0;
	while(newt==0) {


		index = random(sizeof(poem));
//		write("11"+sizeof(poem));
			ann1=strsrch(poem[index],"£¬");
			ann2=0;
			ann3=0;
			poemstr = ({});

			while (ann1 > 0)
			{
				ann3++;
				poemstr += ({ poem[index][ann2..ann1-1]+"£¬" });
				poem[index]=poem[index][ann1+2..];
				ann1=strsrch(poem[index],"£¬");
			}

			poemstr+=({poem[index]});
			newt=1;
			// ÔÚÕâÀïÐ´ºÏ²¢³ÌÊ½£»
			ann2=0;
			for (ann1=0;ann1<sizeof(poemstr) ; ann1++)
			{
				if (strlen(poemstr[ann1]) < 15 && ann1 != sizeof(poemstr)-1)
				{
					poemstr[ann1]+=poemstr[ann1+1];
//					write(HIY+poemstr[ann1]+NOR+"\n");
					ann2++;
					poemstr[ann1+1]="";
				}
			}
			for (ann1=0;ann1<ann2 ; ann1++)
				poemstr-=({""});
//			write(poemstr[0]+"\n");
//			write(poemstr[1]+"\n");
//			write(poemstr[2]+"\n");
/*
			if(sscanf(poem[index],"%s  %s",first,second)==2 &&
			  !sscanf(poem[index],"%*s£Û") && 
			  !sscanf(poem[index],"%*s£¨") &&
			  !sscanf(poem[index],"%*s¡õ") )
			{
				if(strlen(first)>2&&strlen(second)>2)
					newt=1;
			}*/
//	    }
	}
//	current_all=first+"  "+second;
	ans_curr=0;
	ann1=random(sizeof(poemstr));
	quest=poemstr[ann1];
	if (strlen(quest) < 13 && ann1 > 0)
		quest = poemstr[ann1-1]+quest;
		
//	current=replace_string(quest,"£¬","");  // the answer
	current=quest;	// ÒªÇó±êºÅÎ»ÖÃÕýÈ·
	quest=mixup(quest);   // the question
	quest=mixup(quest);   // the question
	curr_show=quest;
	tell_room(this_object(), enscript("ËáÐã²ÅÌá±ÊÔÚÇ½ÉÏÐ´µÀ£º"+quest)+"\n");
    }
    if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
		call_out("do_test1",55);
    else
	running=0;
    return;
}
string mixup(string str)
{
    int len=strlen(str)/2,i,j,k,l;
    string ans;
    for(i=1;i<=random(2)+1;i++) {
	j=random(len);
	k=random(len);
	if(j==k) {
	    k++;
	    if(k>=len) k=0;
	}
	if(j>k) {
	    l=k; k=j; j=l;
	} // so j<k
	j=j+j; k=k+k;
	if(j>0) 
	    ans=str[0..j-1]; 
	else 
	    ans="";
	ans+=str[k..k+1]+str[j+2..k-1]+str[j..j+1];
	if(k<len+len-2) 
	    ans+=str[k+2..len+len-1];
	str=ans;
    }
    return str;
}
int do_look(string arg){   
    int i;
    if(!arg) return 0;
    if(arg=="wall")
	{
	if (wizardp(this_player()))
		write(CYN"µ±Ç°µÄ´ð°¸ÊÇ£º"+current+"\n"NOR);
//	for (i=0;i<length1;i++)	    write("    "+poem1[i]+"\n");
	write("\n\n");
	write(WHT"µ±Ç°ÌâÄ¿£º¡¡¡¡¡¡"+curr_show+"\n"NOR);
	return 1;
    } else if(arg=="ÆôÊÂ") {
	write("\n"+@LONG
           ±¾ÉçÐÂÔö²ÂÊ«ÓÎÏ·£¬ÓÉËáÐã²Å½«Ò»¾äÊ«´ÊµÄÈô¸É×Ö
       µßµ¹´ÎÐò£¬Ð´ÔÚÇ½ÉÏ¡£ÄÜ×¼È·´ð³ö(answer)Ô­¾äÕßÎªÊ¤¡£
       ÒªÏëÖªµÀµ±Ç°ÌâÄ¿£¬¿ÉÒÔÍùÇ½ÉÏ(wall)¿´¡£
       ÀýÈç£ºËáÐã²ÅÌá±ÊÔÚÇ½ÉÏÐ´µÀ£ºÀëÀëÔ­ÉÏ²ÝÒ»ÈÙÒ»¿ÝËê
       ÄãÓ¦¸Ã»Ø´ð£ºanswer ÀëÀëÔ­ÉÏ²ÝÒ»ËêÒ»¿ÝÈÙ
LONG);
	write("\n");
	return 1;
    } else 
	return 0;
}
void copy_to_old()
{    int i;
    object ob;
    length1=length;
    poem1=({});
    last="";
    for (i=0;i<length;i++)
	poem1+=({poem[i]});
    if(objectp(ob=present("suan xiucai",this_object()))
      && random(2)==7 && living(ob)) {
	message_vision(({ob->name()+"Ò¡Í·»ÎÄÔµØÒ÷ËÐµÀ£º",
	    ob->name()+"¸ßÉùÀÊ¶ÁµÀ£º",
	    ob->name()+"·Â·ðÔÚ×ÔÑÔ×ÔÓï£º"})[random(3)]+"\n",ob);
	for (i=0;i<length1;i++) {
	    message_vision("    "+poem1[i]+"\n",ob);
	}
	message_vision("\n",ob);
    }
    return;
}
void new_poem()	{   
    string filename,buf;
    int i,j,k;

	string *line,lines;
    length=0;




		filename=query("file");
		k=1;
		i=0;
		j=0;
		poem=({});


/*
		while(buf=read_file(filename,1+i,1))
		{
			if(strlen(buf)>2)
			{
			buf=replace_string(buf,"\n","");
			poem+=({buf});
			j++;
			}
			i++;
		}
		length=j;

		write("22"+read_file(filename,1+i,1)+"\n"+"i="+i+"\n");

		*/

		// hmm, seems bug here.
		// lemme write a new code, dont use this dumb one.
		lines=read_file(filename);



	if(lines)
	{  
		line = explode(lines,"\n");
		for (i=0; i<sizeof(line); i++)
			if (strlen(line[i])>2 && line[i][0..1]!="##")
			{
			poem+=({replace_string(line[i],"\n","")});
			j++;
			}
	}
	length=j;
//	write("333"+length+"---"+sizeof(explode(read_file(filename),"\n"))+"\n");
	
    poem_index=k;
    answerd=0;
    index=-1;
    chance=3*100/(1+length);
	if (length == 2)
		chance=50;
//    if(length<3)	chance=100;
    return;
}

int find_newline()
{
    index++;
//	write("index = "+index+" length="+length+" chance="+chance+"\n");
    while(index<length)
	{
		if(random(100)<chance)
			return 1;
		else
			index++;
    }
    return 0;
}
string enscript(string arg)
{    string result;
    string *color=({BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
      HIR,HIG,HIY,HIB,HBRED,HBGRN,HBYEL,
      HBBLU,HBMAG,BBLK,BRED,BGRN});
    int len,i;
    len=sizeof(color);
    result="";
    i=sizeof(arg);
    while(i>2) {
	if(random(2)==0) {
	    result=color[random(len)]+NOR+arg[i-2..i-1]+result;
	} else {
	    result=arg[i-2..i-1]+result;
	}
	i-=2;
    }
    result=NOR+arg[0..1]+result;
    return result;
}
