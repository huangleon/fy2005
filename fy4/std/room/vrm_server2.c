/************************************************
 * vrm_server.c                                 *
 * ���������Թ������� (Virtual Random Maze)   *
 *                                              *
 * by Find.                                     *
 * modified by suu to make it work in fy        *
 * modified by silencer to make it more fun :D	*
 * modified by annie to make it support Z-Line	*
 ************************************************/

/******************************************************
 * �Թ���һ����Ϸ�ﾭ��Ҫ�õ��Ķ�������ǰ���Թ�����Ҫ *
 * ��ʦһ������һ��������ֹ����ƣ���ʱ����������һ�� *
 * ������ҳ���ȷ����·���Թ���ֱ�й©���Թ��Ͳ����� *
 * Ϊ�Թ��ˣ�������ʦ�Ƕ��ʾ���֭���Թ���Ƶľ�������,*
 * ���ٸ��ӵ��Թ�����Ҳ�ᱻ�ҵ���ȷ��·�ߣ����ҹ��ڸ� *
 * �����ߵ��Թ�Ҳʹ��Ҹо����ڷ�����������Ȥ����˲� *
 * �����뷨��                                         *
 * ����Թ��Ĳ����㷨�����򵥣��Թ��Ĵ��澡����ʡ���� *
 * �壬�Թ������������������������Թ�����ֻ���� *
 * ����ߵ�ʱ�Ż�װ���ڴ棬�����Թ�����Ҳ����ͨ��ROOM *
 * һ����һ��ʱ��û�б��ο����������ٽ�ʡ�����壬���� *
 * ���Թ�һ��ʱ��û�б��ο������Ա���ȫ�ݻ٣��´����� *
 * Ҫ��ʱ������½������ֻ����һ���µ��Թ���������ʦ *
 * д������Թ�ֻ��涨һЩԤ��Ĳ������Թ��ĵ��߳��� *
 * �����������������������ʮ��������ǧ�����䡢·��ʱ *
 * ʱ��ͬ������Թ��ͽ������ˣ�������������д��Ч�� *
 * ����Ϸ�Ŀ����ԡ�                                   *
 * �����Ŀǰ�ʺ���������Թ��������Թ��ڷ���������� *
 * ����ͬ������һƬ���֡�һƬ�صصȣ���Ҫ����������� *
 * �������������һ������ڡ�һ����ֵ���������Ҫ *
 * �����Լ�������涨���Թ��ڷ���������һЩ����ʹ�� *
 * �ڷ���������仯�������������������Э�������Ը *
 * ����ʦ����ֻ�����Թ�������Ӳ��֣����ü����Թ���� *
 * ��һ����ȫ��������򣬹������Ժ�����ʦ�����ɶ��ˡ� *
 * Ŀǰ����Ϸʹ�õ��Թ�һ��Ϊ���߳�10��40������������ *
 * ����Թ���Ҳ��֪��������Դ���һ��˵����Ҫ�����Լ� *
 * �ķ���������������������������ͨ�Ļ�������һ����� *
 * Ϊ100x100���Թ�Ӧ��Ҳ��һ�����ɵ����顣            *
 * ���ڲ��� virtual object��ǣ�浽һ�㰲ȫ���⣬��Ҫ��*
 * ���Լ���ϵͳ����������                             *
 ******************************************************/

#pragma optimize

#define UP		32	// damn,ansi.h already defined U
#define D		16
#define N		8
#define S		4
#define W		2
#define E		1
#define ALL		63

/****************************************************
 * �Թ��ĵ��߳����ֵĿǰ�ݶ�Ϊ 100����������Թ���
 * ����Ͳ����ȽϺķ���Դ���߳� 100 ���Թ�'���'����
 * 100x100 ���� 10000 �������һ���Թ���һ���������
 * ������һ���ʵʱ�Թ���ʵʱ�Թ���ָ����Ϸ���й���
 * ����ʱ�� destruct ������Ҫ�ֻ���ʱ���������Թ�����
 * ���߳��� 10 �� 50 ֮��Ϊ�ˡ����贴������Թ����м�
 * ������ʮ�����������Թ���Ӧ������������������Ϸ��
 * ��ʱ������Ϸ������һ��ʱ�䣨����20�룩��ֹ��ҵ��롣
 * ��Ϸͨ�������������������´��Թ���
 * ��֪˭���õ���ô����Թ�������������
 ****************************************************/
#define MAX_LONG	100

// ֻҪ�����������������ķ���Ϳ϶���һ�����.
// �����ܵĳ��������.
// define ����涨�������ֻ������������.
// Ҳ���Ƕ�����������ڵķ��������ر�����.
// ����ʹ������ڿ������������г��ںܷ�
// ������Ϸ��Ȥ��
#define VALID_LEAVES 3

inherit F_CLEAN_UP;
#include <ansi.h>;

class coordinate{ int x; int y; int z;}
class coordinate *newpath = ({}),/*���������*/
	enter,/* ������� */
	leave;/* �������� */

private string *valid_dirs = ({ "south","north","west","east","up","down",});
private mapping reverse_dir = ([
"north" : "south",
"south" : "north",
"west"  : "east",
"east"  : "west",
"down"	: "up",
"up"	: "down",
]);


// ȫ�Թ���������.
private mixed *all;

/***************** �Թ���һЩԤ�����ԣ�*****************/
private int l;				// �Թ��Ķ����򵥱߳�
private int m;				// �Թ����ϱ��򵥱߳�
private int h;				// �Թ��ĸߵ��򵥱߳�
private int s;				// �Թ�ÿ����������������������
private string *inherit_rooms = ({});	// �Թ�����̳еĵ�������
private string entry_dir;		// �Թ���ڷ���
private string link_entry_dir;		// �Թ��������������ӷ���
private string link_entry_room;		// �Թ�������������򵵰����ļ���
private int link_entry_room_x;		// �Թ���ڵ�x����
private int link_entry_room_y;		// �Թ���ڵ�y����
private int link_entry_room_z;		// �Թ���ڵ�z����
private string link_exit_dir;		// �Թ���������������ӷ���
private string link_exit_room;		// �Թ��������������򵵰����ļ���
private string entry_short;		// �Թ���ڵĶ�����
private string entry_desc;		// �Թ���ڵĳ�����
private string exit_short;		// �Թ����ڵĶ�����
private string exit_desc;		// �Թ����ڵĳ�����
private string *maze_room_desc	= ({});	// �Թ�����ĳ�����
private string maze_room_short;		// �Թ�����Ķ�����
private int is_outdoors = 0;		// �Թ������Ƿ�Ϊ����
private int refresh_delay = 0;  	//�Թ��ؽ�ʱ��, default is 0 means no recreation
private int private_flag;				// Privite Maze? // annie. 09.2003
/******************* ---- END ---- *********************/

// �������.
private int maze_built = 0;

// ����ȫ�����.
private void refresh_vars();

// �����Թ�
private void create_maze();

// ѡ���������.
private int random_out(int x,int y,int z,int n);

//�����Թ���λ��
private void set_maze_spacing(int space);

// ��������.
private void link_to_north(int x,int y,int z);
private void link_to_south(int x,int y,int z);
private void link_to_west(int x,int y,int z);
private void link_to_east(int x,int y,int z);
private void link_to_up(int x,int y,int z);
private void link_to_down(int x,int y,int z);

// �����ѽ����Թ��ĵ�ͼ.
private void paint_vrm_map();

// ���ĳ���������Ƿ��� players
private int player_in(object m_room);

// ȥ���Թ� --- ����players��ȥVOID
private void remove();

// ���´����Թ�
private void refresh_maze();

// ������Ϣ��
private string mroom_fname(int x,int y,int z)
	{ return sprintf("%s/%d/%d/%d",base_name(this_object()),x,y,z);}
	
int query_maze_length(){
	return l;
}	

int query_maze_height(){
	return m;
}

int query_maze_altitude(){
	return h;
}

// ����ȫ�����.
private void refresh_vars() 
{
	newpath = ({});
	all = 0;
}

// ��һЩ��������ĺϷ��Լ��
private int check_vars()
{
	int i,n;

	if( (l < 2) || l > MAX_LONG )
		return 0;

	if( (m < 2) || m > MAX_LONG )
		return 0;
		
	if( h > MAX_LONG )
		return 0;
		
	inherit_rooms -=({0});
	if( !n = sizeof(inherit_rooms) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(inherit_rooms[i]) || (inherit_rooms[i] == ""))
			return 0;

	if(!stringp(entry_dir) || (member_array(entry_dir,valid_dirs) == -1) )
		return 0;

	if(!stringp(link_entry_room) || (link_entry_room == ""))
		return 0;

	if(!stringp(link_exit_room) || (link_exit_room == ""))
		return 0;

	if(!stringp(entry_short) || (entry_short == ""))
		return 0;

	if(!stringp(exit_short) || (exit_short == ""))
		return 0;

	if(!stringp(entry_desc) || (entry_desc == ""))
		return 0;

	if(!stringp(exit_desc) || (exit_desc == ""))
		return 0;

	maze_room_desc -=({0});
	if( !n = sizeof(maze_room_desc) )
		return 0;

	for(i=0;i<n;i++)
		if(!stringp(maze_room_desc[i]) || (maze_room_desc[i] == ""))
			return 0;

	if(!stringp(maze_room_short) || (maze_room_short == ""))
		return 0;

	return 1;
}


private int random_out(int x,int y,int z,int n) // ѡ��������ں���.
{
	int *outs = ({}), retn = 0;
	class coordinate temp;

	// The west room is (x-1,y)
	if( n&W
	&& ((x-1) >= 0)
	&& !all[x-1][y][z] )
	{
		temp = new(class coordinate);
		temp->x = x-1;
		temp->y = y;
		temp->z = z;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ W });
	}

	// The east room is (x+1,y)
	if( n&E
	&& ((x+1) < l)
	&& !all[x+1][y][z] )
	{
		temp = new(class coordinate);
		temp->x = x+1;
		temp->y = y;
		temp->z = z;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ E });
	}

	// The south room is (x,y-1)
	if( n&S
	&& ((y-1) >= 0)
	&& !all[x][y-1][z] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y-1;
		temp->z = z;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ S });
	}

	// The north room is (x,y+1)
	if( n&N
	&& ((y+1) < m)
	&& !all[x][y+1][z] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y+1;
		temp->z = z;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ N });
	}

	// The up room is (x,y,z+1)
	if( n&UP
	&& ((z+1) < h)
	&& !all[x][y][z+1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y;
		temp->z = z+1;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ UP });
	}

	// The down room is (x,y,z-1)
	if( n&D
	&& ((z-1) >= 0)
	&& !all[x][y][z-1] )
	{
		temp = new(class coordinate);
		temp->x = x;
		temp->y = y;
		temp->z = z-1;

		// ����ķ��䲻�ڴ������б� newpath ��.
		//if( member_array(temp,newpath) == -1 )
			outs += ({ D });
	}

#ifdef VALID_LEAVES
	// �������������,����ر�һ��.	// ann' marked
//	if(sizeof(outs) >= 3)
	while(sizeof(outs) >= VALID_LEAVES)
		outs -= ({ outs[random(sizeof(outs))] });
#endif

	for(int i=0;i<sizeof(outs);i++)
		retn |= outs[i];

	return retn;
}

private void create_maze()
{
	int i,j;
	class coordinate *valid_leaves=({}),temp;

	refresh_vars(); // ����ȫ�����.
	if( !check_vars() )   // ��һЩԤ��������м�顣
		return;

	// 1.ȷ���Թ����߳�.
	all = allocate(l);
	for(i=0;i<l;i++)
		all[i] = allocate(m);	// ��������.
	for(i=0;i<l;i++)
		for(j=0;j<m;j++)
			all[i][j] = allocate(h);	// ��������.
	
	CHANNEL_D->do_sys_channel("sys",sprintf("Start buliding maze"));
	CHANNEL_D->do_sys_channel("sys",sprintf("Start buliding maze in %s",base_name(this_object())));
	
	enter = new(class coordinate);

	switch (entry_dir)
	{
		case "south":
			// enter �������.
			enter->x = to_int(l/2); // ȡ���Թ��Ƚ�ƽ�⡣
			enter->y = 0;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= S;
			break;
		case "north":
			enter->x = to_int(l/2);
			enter->y = m-1;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= N;
			break;
		case "west":
			enter->y = to_int(m/2);
			enter->x = 0;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= W;
			break;
		case "east":
			enter->y = to_int(m/2);
			enter->x = l-1;
			enter->z = 0;
			all[enter->x][enter->y][enter->z] |= E;
			break;
		case "up":
			enter->z = h-1;
			enter->y = to_int(m/2);
			enter->x = to_int(l/2);
			all[enter->x][enter->y][enter->z] |= UP;
			break;
		case "down":
			enter->z = 0;
			enter->y = to_int(m/2);
			enter->x = to_int(l/2);
			all[enter->x][enter->y][enter->z] |= D;
			break;
	}

	// ������������.
	newpath += ({ enter });

	// ������ѭ��.
	do
	{
		int x,y,z,out,numb;

		// ����һЩ������ʼ��.
		if( !(numb=sizeof(newpath)) )
			continue;
		numb = random(numb);
		reset_eval_cost();
		x = newpath[numb]->x;
		y = newpath[numb]->y;
		z = newpath[numb]->z;

		// ������������ܵĳ�������ر�һ������:
		out = ALL^(all[x][y][z]);
		out = random_out(x,y,z,out);

		if(!out) // û�п��ܵĳ�����.
		{
			newpath -= ({ newpath[numb] });
			continue;
		}

		// ��������.
		if(out&W) link_to_west(x,y,z);
		if(out&E) link_to_east(x,y,z);
		if(out&N) link_to_north(x,y,z);
		if(out&S) link_to_south(x,y,z);
		if(out&UP) link_to_up(x,y,z);
		if(out&D) link_to_down(x,y,z);

		// ��ǰ���䴦�����.
		newpath -= ({ newpath[numb] });
	}
	while (sizeof(newpath));

	switch (entry_dir)
	{
		case "west":
			for(i=0;i<m;i++)
				for(j=0;j<h;j++)
					if(all[l-1][i][j])
					{
						temp = new(class coordinate);
						temp->x = l-1;
						temp->y = i;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "east":
			for(i=0;i<m;i++)
				for(j=0;j<h;j++)
					if(all[0][i][j])
					{
						temp = new(class coordinate);
						temp->x = 0;
						temp->y = i;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "south":
			for(i=0;i<l;i++)
				for(j=0;j<h;j++)
					if(all[i][m-1][j])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = m-1;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "north":
			for(i=0;i<l;i++)
				for(j=0;j<h;j++)
					if(all[i][0][j])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = 0;
						temp->z = j;
						valid_leaves += ({temp});
					}
			break;
		case "up":
			for(i=0;i<l;i++)
				for(j=0;j<m;j++)
					if(all[i][j][0])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = j;
						temp->z = 0;
						valid_leaves += ({temp});
					}
			break;
		case "down":
			for(i=0;i<l;i++)
				for(j=0;j<m;j++)
					if(all[i][j][h-1])
					{
						temp = new(class coordinate);
						temp->x = i;
						temp->y = j;
						temp->z = h-1;
						valid_leaves += ({temp});
					}
			break;
	}

	if( !(i=sizeof(valid_leaves)) ) // û�г��� �����½���
	{
		call_other(this_object(),"create_maze");
		return;
	}

	if(i == 1)
		leave = valid_leaves[0];
	else
		leave = valid_leaves[random(i)]; // ���ѡһ��.

	switch (entry_dir)
	{
		case "south":
			all[leave->x][leave->y][leave->z] |= N;
			break;
		case "north":
			all[leave->x][leave->y][leave->z] |= S;
			break;
		case "west":
			all[leave->x][leave->y][leave->z] |= E;
			break;
		case "east":
			all[leave->x][leave->y][leave->z] |= W;
			break;
		case "up":
			all[leave->x][leave->y][leave->z] |= D;
			break;
		case "down":
			all[leave->x][leave->y][leave->z] |= UP;
			break;
	}

	// �Թ�������ϡ�
	maze_built = 1;
	
	if (refresh_delay > 0  )
	{
		EVENT_D->add_event(time()+refresh_delay,this_object(),(:refresh_maze:));
	}
	
	// ������ɵ��Թ���ͼ��
	// ��ͼ�ļ�ΪͬĿ¼��ͬ����'.map' �ļ���
	// ���Ƶ�ͼҲ�������������ʦ�Ĺ�����
	// ����Ҫ�ɿ���������ڱ�Ŀ¼��'д'��
		    paint_vrm_map();	// ann' marked
}




private void link_to_west(int x,int y,int z)	// The west room is (x-1,y)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ���������ķ�����.
	if( (x-1) < 0 )
		return;

	temp = new(class coordinate);
	temp->x = x-1;
	temp->y = y;
	temp->z = z;

	// ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= W;
	all[temp->x][temp->y][temp->z] |= E;
	newpath += ({temp});
}

private void link_to_east(int x,int y,int z)	// The east room is (x+1,y)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������ķ�����.
	if( (x+1) >= l )
		return;

	temp = new(class coordinate);
	temp->x = x+1;
	temp->y = y;
	temp->z = z;

	// ����ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= E;
	all[temp->x][temp->y][temp->z] |= W;
	newpath += ({temp});
}

private void link_to_south(int x,int y,int z)	// The south room is (x,y-1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������϶˵ķ�����.
	if( (y-1) <0 )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y-1;
	temp->z = z;

	// �϶˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= S;
	all[temp->x][temp->y][temp->z] |= N;
	newpath += ({temp});
}

private void link_to_north(int x,int y,int z)	// The north room is (x,y+1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ�����˵ķ�����.
	if( (y+1) >= m )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y+1;
	temp->z = z;

	// ���˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= N;
	all[temp->x][temp->y][temp->z] |= S;
	newpath += ({temp});
}

private void link_to_up(int x,int y,int z)	// The up room is (x,y,z+1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������ϲ�ķ�����.
	if( (z+1) >= h )
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y;
	temp->z = z+1;

	// ���˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= UP;
	all[temp->x][temp->y][temp->z] |= D;
	newpath += ({temp});
}

private void link_to_down(int x,int y,int z)	// The up room is (x,y,z-1)
{
	class coordinate temp;
	// can't link. ��ǰ�����Ѿ������²�ķ�����.
	if( (z-1) < 0)
		return;

	temp = new(class coordinate);
	temp->x = x;
	temp->y = y;
	temp->z = z-1;

	// ���˵ķ����Ѿ��� path ��,���� ���ڴ������б� newpath ��.
	if(all[temp->x][temp->y][temp->z] /*|| member_array(temp,newpath)*/)
		return;

	all[x][y][z] |= D;
	all[temp->x][temp->y][temp->z] |= UP;
	newpath += ({temp});
}

// �����ѽ����Թ��ĵ�ͼ.
// ann' marked ��ʱ���д˺�ʽ��
private void paint_vrm_map()
{
	string hor = "��" ,ver = "��  ",room = "��",sroom = "��",ld = "��", lu = "��", lb = "��";
	int x,y,z;
	string output = "",map_file;

	for (z = (h-1); z>=0; z--)
	{
		for(y=(m-1);y>=0;y--)
		{
			reset_eval_cost();

			output += sprintf("y=%-3d: ",y);
			for(x=0;x<l;x++)
			{
				if ( (x==enter->x && y==enter->y && z == enter->z)
					|| (x==leave->x && y==leave->y && z == leave->z) )
				{
					output += sroom;
				}
				else if ((all[x][y][z])&UP && (all[x][y][z])&D)
				{
					output += lb;
				}
				else if ((all[x][y][z])&UP)
				{
					output += lu;
				}
				else if ((all[x][y][z])&D)
				{
					output += ld;
				}
				else
				{
					output += room;
				}

				if( (all[x][y][z])&E ) // have east
					output += hor;
				else
					output += "  ";
			}

			output += "\n";
			output += "       ";
			for(x=0;x<l;x++)
			{
				if( (all[x][y][z])&S ) // have south
					output += ver;
				else
				output += "    ";
			}
			output += "\n";
		}
		output += "\nFloor "+z+"\n ------------------------------\n";
	}

	map_file = sprintf( "%s.map",base_name(this_object()) );
	write_file(map_file,output,1);
}

nomask int clean_up()
{
	string fname;
	int x,y,z;
	object *maze_objs = ({}),link_room;

	if(!maze_built)
	{
		destruct(this_object());
		return 0;
	}

	fname = base_name(this_object());

	if( objectp(link_room = find_object(sprintf("%s/entry",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	if( objectp(link_room = find_object(sprintf("%s/exit",fname))) )
	{
		link_room->clean_up();
		if( objectp(link_room) )
			return 1;
	}

	for(x=0;x<l;x++)
		for(y=0;y<m;y++)
			for(z=0;z<h;z++)
				if(objectp(find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))))
					maze_objs += ({find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))});

	maze_objs->clean_up();
	maze_objs -= ({0});

	if(sizeof(maze_objs))
		return 1;
	else
	{
		destruct(this_object());
		return 0;
	}
}

// ��ʦ���� update �����Թ������ǿ�Ƹ����Թ���
// ����ʱ�Թ��е���Ҿ�Ҫȥ VOID �ˡ�

void remove()
{
	string fname = base_name(this_object());
	object m_room;
	int x,y,z;
	
	for(x=0;x<l;x++)
		for(y=0;y<m;y++)
			for(z=0;z<h;z++)
				if(objectp(m_room = find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))))
					destruct(m_room);
	if(objectp(m_room = find_object(sprintf("%s/entry",fname))))
		destruct(m_room);
	if(objectp(m_room= find_object(sprintf("%s/exit",fname))))
		destruct(m_room);
}

void refresh_maze()
{
	if (this_object()->has_player())
	{
		//has players in maze re-try 10 mins later;
		CHANNEL_D->do_sys_channel("sys","maze has players in, will retry 10 mins later");
		EVENT_D->add_event(time()+600,this_object(),(: refresh_maze :));
		return;
	}
	remove();
	CHANNEL_D->do_sys_channel("sys","maze destructed");
	destruct(this_object());
	return;
}

//	����Թ����Ƿ������
int has_player()
{
	string fname = base_name(this_object());
	object m_room;
	int x,y,z;

	for(x=0;x<l;x++)
	{
		for(y=0;y<m;y++)
		{
			for(z=0;z<h;z++)
			{
				if(objectp(m_room = find_object(sprintf("%s/%d/%d/%d",fname,x,y,z))))
					if (player_in(m_room))
						return 1;
			}
		}
	}
				
	if(objectp(m_room = find_object(sprintf("%s/entry",fname))))
		if (player_in(m_room))
			return 1;

	if(objectp(m_room = find_object(sprintf("%s/exit",fname))))
		if (player_in(m_room))
			return 1;
	return 0;
}

//	���ĳ���������Ƿ�����ҡ�

int player_in(object m_room)
{
	object *inv;
	inv = all_inventory(m_room);
	for (int i = 0;i < sizeof(inv) ; i++)
		//if player in the room return
		if (userp(inv[i]))
			return 1;

	return 0;
}


//	��������Ҵ��Թ�����ߡ�
int remove_all_players(object maze_room,object exile_room,string remove_msg){
	
	string fname = base_name(maze_room);
	object m_room,*inv;
	int x,y,z,k,num,length,height,altitude;

	length=maze_room->query_maze_length();
	height=maze_room->query_maze_height();
	altitude=maze_room->query_maze_altitude();
	
	
	for(x=0;x<length;x++)
	{
		for(y=0;y<height;y++)
		{
			for(z=0;z<altitude;z++)
			{
				if(objectp(m_room = find_object(sprintf("%s/%d/%d/%d",fname,x,y,z)))) {
					tell_room(m_room,remove_msg);
					inv=all_inventory(m_room);
					num=sizeof(inv);
					while(num--) {
						if (userp(inv[num])) 
							inv[num]->move(exile_room);	
						if (inv[num]->query("possessed"))
						if (userp(inv[num]->query("possessed")))
							inv[num]->move(exile_room);	
					}	
				}	
			}
		}
	}
				
	if(objectp(m_room = find_object(sprintf("%s/entry",fname)))) {
		tell_room(m_room,remove_msg);
		inv=all_inventory(m_room);
		num=sizeof(inv);
		while(num--) {
			if (userp(inv[num]))
				inv[num]->move(exile_room);	
			if (inv[num]->query("possessed"))
			if (userp(inv[num]->query("possessed")))
				inv[num]->move(exile_room);	
		}
	}
	
	if(objectp(m_room = find_object(sprintf("%s/exit",fname))))	{
		tell_room(m_room,remove_msg);
		inv=all_inventory(m_room);
		num=sizeof(inv);
		while(num--) {
			if (userp(inv[num]))
				inv[num]->move(exile_room);
			if (inv[num]->query("possessed"))
			if (userp(inv[num]->query("possessed")))
				inv[num]->move(exile_room);		
		}
	}
	
}



/**** ������Ԥ���Թ������Ľӿں��� ****/
// �Թ��ĵ��߳�
void set_maze_long(int mlong, int mheight,int maltitude)
{
	if(!intp(mlong) || !intp(mheight))
		return;

	if (!intp(maltitude))
		maltitude = 0;

	// ��СΪ 5����С��ûʲô���塣
	if( (mlong < 2) || mlong > MAX_LONG 
		|| mheight<2 || mheight > MAX_LONG || maltitude > MAX_LONG)
		return;

	l = mlong;
	m = mheight;
	h = maltitude;
}

// �Թ��������̳е�����ĵ������ơ�
void set_inherit_room( mixed rooms )
{
	if(stringp(rooms))
	{
		// �˵����Ƿ����
		if(file_size(sprintf("%s.c",rooms)) > 0)
			inherit_rooms = ({ rooms });
		return;
	}

	else if(arrayp(rooms))
	{
		foreach(string f in rooms)
		{
			if(!stringp(f) || f == "")
				return;
			if(file_size(sprintf("%s.c",f)) <= 0)
				return;
		}
		inherit_rooms = rooms;
		return;
	}

	return;
}

// ��ڷ���(�����ڶ���)
void set_entry_dir(string dir)
{
	if(!stringp(dir))
		return;
	
	if (dir == "maze_enter")
	{
		dir="north";
		private_flag=1;
	}
	else
		private_flag=0;	

	// ��ڷ���ĺϷ��Լ��.
	if(member_array(dir,valid_dirs) == -1)
		return;

	entry_dir = dir;
}

//�������������ӷ���
void set_link_entry_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_entry_dir = dir;
}

// �Թ�������������򵵰����ļ���
void set_link_entry_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_entry_room = lroom;
}

// �Թ���ڷ�������꣬�����޷��ü򵥵ķ������Թ����갲����
// ����/�����ڣ������Ҫ�õ��Թ�������Ĺ�ϵ��
// ����������Ϊ�Թ��ǽ������������һ���֣����߳��Թ�����ʱ����Ծ������һ������
// ȱ���ǣ�һ�����Թ��������������ʵ�����ص��������Ҫ������Լ������ˣ�
// ����˵����Ҫ��100x100���Թ������� (1,1)�� (10,10)֮�䡣�������Լ���һ�°�

void set_link_entry_room_x(int x)
{
	if(!intp(x)) link_entry_room_x=0;
		else	link_entry_room_x = x;
}


void set_link_entry_room_y(int y)
{
	if(!intp(y)) link_entry_room_y=0;
		else	link_entry_room_y = y;
}


void set_link_entry_room_z(int z)
{
	if(!intp(z)) link_entry_room_z=0;
		else	link_entry_room_z = z;
}


//�����Թ���λ��
void set_maze_spacing(int space) {
	if (!intp(space)) s=10;
		else s=space;
}


//��������������ӷ���
void set_link_exit_dir(string dir)
{
	if(!stringp(dir) || dir == "")
		return;

	link_exit_dir = dir;
}

// �Թ��������������򵵰����ļ���
void set_link_exit_room(string lroom)
{
	if(!stringp(lroom) || lroom == "")
		return;

	if(file_size(sprintf("%s.c",lroom)) <= 0)
		return;

	link_exit_room = lroom;
}

// �Թ���ڵĶ�����
void set_entry_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_short = desc;
}

// �Թ���ڵĳ�����
void set_entry_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	entry_desc = desc;
}

// �Թ����ڵĶ�����
void set_exit_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_short = desc;
}

// �Թ����ڵĳ�����
void set_exit_desc(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	exit_desc = desc;
}

//�Թ�����Ķ�����
void set_maze_room_short(string desc)
{
	if(!stringp(desc) || desc == "")
		return;

	maze_room_short = desc;
}

//�Թ����������������ж�������������ÿ����
//���ʱ���������ѡ��һ����
void set_maze_room_desc(mixed desces)
{
	if(stringp(desces))
	{
		maze_room_desc = ({ desces });
		return;
	}

	if(arrayp(desces))
	{
		foreach(string desc in desces)
			if(!stringp(desc))
				return;
		maze_room_desc = desces;
		return;
	}
}

//�Թ������Ƿ�Ϊ���ⷿ��
void set_outdoors(int outd)
{
	if(!intp(outd))
		return;

	if(outd)
		is_outdoors = 1;
}

//�Թ�ˢ��
void set_maze_refresh(int m_refresh)
{
	if (intp(m_refresh) && m_refresh>=1)
		refresh_delay = m_refresh; 
}

/*	*** ������Ԥ���Թ������Ľӿں��� ***

		
		
		***************** �����Ǵ����Թ��������� ************************


//	�Թ��еĹ�������--	��ԭ����vrm_server��ȥ�����ⲿ�����ݣ�
	һ���õ��Թ�����������һ��������д��NPC�ķֲ���������һЩ�ϸ��ӵĶ����
	�ж���ʹ����Ի�����������ʹ�õķ������ڵ���ʱ��inherit_roomȥ�̳�һ����
	�Թ������йص�maze-room��������ļ�����Զ���NPC/obj������valid_leave,
	add_action�ȵȡ�
	Ҳ����˵���Թ����ļ�����
	1���Թ������ļ� -- �����Թ���С����λ�������������Թ������ļ�
	2���Թ����䶨���ļ�--�Թ�����ľ��嶨��
	3�����ļ�
	
// 	�����Թ����䣬�� VIRTUAL_D ���á�*/

nomask object query_maze_room(string str)
{
	int idx,idx2,x,y,z,exits;
	object ob;
	string f;
	
    	seteuid(ROOT_UID);
	seteuid(geteuid());
	if( previous_object() && (geteuid(previous_object()) != ROOT_UID) )
		return 0;

	if(!stringp(str) || str == "")		return 0;

	if(!maze_built)	// �Թ�δ����
		create_maze();
	if(!maze_built)		return 0;


	if(str == "entry")	// �Թ���ڷ���
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];
                                               
		//ob = new(f);
		ob = load_object(f);
		if(!ob)	return 0;
		ob->set("virtual_room",1);
		ob->set("short",entry_short);
		ob->set("long",entry_desc);
		if (is_outdoors)	ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_entry_dir),link_entry_room);
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),mroom_fname(enter->x,enter->y,enter->z));
		ob->set("coor/x",link_entry_room_x);
		ob->set("coor/y",link_entry_room_y);
		ob->set("coor/z",link_entry_room_z);
		ob->set("no_fly",1);
		ob->set("entry_room",1);
		ob->set("perma_exist",1);
		ob->setup_entry_room();
		return ob;
	}

	if(str == "exit")	// �Թ����ڷ���
	{
		f = inherit_rooms[random(sizeof(inherit_rooms))];

		//ob = new(f);
		ob = load_object(f);
		if(!ob)	return 0;
		ob->set("no_fly",1);
		ob->set("perma_exist",1);
		ob->set("virtual_room",1);
		ob->set("short",exit_short);
		ob->set("long",exit_desc);
		if(is_outdoors)		ob->set("outdoors",1);
		ob->set(sprintf("exits/%s",link_exit_dir),link_exit_room);
		ob->set(sprintf("exits/%s",entry_dir), mroom_fname(leave->x,leave->y,leave->z));
		switch (entry_dir) {
			case "east":	ob->set("coor/x",link_entry_room_x - l*s - 2*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "west":	ob->set("coor/x",link_entry_room_x + l*s +2*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "south":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + m*s +2*s);
					ob->set("coor/z",link_entry_room_z);
					break;
			case "north":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y - m*s -2*s);
					ob->set("coor/z",link_entry_room_z);
					break;		
			case "up":	ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z - h*s -2*s);
					break;		
			case "down":ob->set("coor/x",link_entry_room_x + (leave->x - enter->x)*s);
					ob->set("coor/y",link_entry_room_y + (leave->y - enter->y)*s);
					ob->set("coor/z",link_entry_room_z + h*s +2*s);
					break;		
		}
		ob->set("exit_room",1);
		ob->setup_exit_room();
		return ob;
	}

	idx = member_array('/', str);
	if( idx == -1 )
		return 0;

	if(!sscanf(str[0..idx-1],"%d",x))		return 0;

	idx2 = member_array('/', str[idx+1..]);
	if( idx2 == -1 )
		return 0;

	if(!sscanf(str[idx+1..idx+idx2],"%d",y))		return 0;
	if(!sscanf(str[idx+idx2+2..],"%d",z))		return 0;

	if( !exits = all[x][y][z] )		return 0;

	f = inherit_rooms[random(sizeof(inherit_rooms))];

	ob = load_object(f);
	if(!ob)
		return 0;

	ob->set("virtual_room",1);
	ob->set("perma_exist",1);
	ob->set("no_fly",1);
	
//	�������������Թ���С�����巿������
	switch (entry_dir) {
		case "east":	ob->set("coor/x",x*s-l*s+link_entry_room_x-s);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "west":	ob->set("coor/x",x*s+link_entry_room_x+s);
				ob->set("coor/y",y*s-to_int(m/2)*s+link_entry_room_y);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "south":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s+link_entry_room_y +s);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "north":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-m*s+link_entry_room_y-s);
				ob->set("coor/z",link_entry_room_z);
				break;
		case "up":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",z*s-h*s+link_entry_room_z-s);
				break;
		case "down":	ob->set("coor/x",x*s-to_int(l/2)*s + link_entry_room_x);
				ob->set("coor/y",y*s-to_int(m/2)*s + link_entry_room_y);
				ob->set("coor/z",z*s+link_entry_room_z+s);
				break;
	}		
				

//	setting exits directions:
	if(exits&W)
		ob->set("exits/west",mroom_fname(x-1,y,z));
	if(exits&E)
		ob->set("exits/east",mroom_fname(x+1,y,z));
	if(exits&N)
		ob->set("exits/north",mroom_fname(x,y+1,z));
	if(exits&S)
		ob->set("exits/south",mroom_fname(x,y-1,z));
	if(exits&UP)
		ob->set("exits/up",mroom_fname(x,y,z+1));
	if(exits&D)
		ob->set("exits/down",mroom_fname(x,y,z-1));

	if( (x == enter->x) && (y == enter->y) && (z == enter->z))
		ob->set(sprintf("exits/%s",entry_dir),
			sprintf("%s/entry",base_name(this_object())));
	if( (x == leave->x) && (y == leave->y)  && (z == leave->z))
		ob->set(sprintf("exits/%s",reverse_dir[entry_dir]),
			sprintf("%s/exit",base_name(this_object())));

	
	if(is_outdoors)		ob->set("outdoors",1);

//	ָ���Թ����䶨���ļ����趨��������
	
	f->setup_room_desc(ob,l,m,x,y,z);	
	
//	ָ���Թ����䶨���ļ����趨����/��Ʒ	
	f->setup_npc_obj(ob,l,m,x,y,z);
	
//	ָ���Թ����䶨���ļ����趨��Ʒ����
	
	return ob;
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
